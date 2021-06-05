#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

/*******************************************************************************
 * CircularBuffer.h
 *
 * Author: Ángel Pérez
 *
 *******************************************************************************/

/* Include section
 *******************************************************************************/
#include <mutex>
#include <memory>
#include <iostream>

/* Defines section
 *******************************************************************************/

/* Class declaration and definition
 *******************************************************************************/
namespace utils {
  template <typename E>
    class CircularBuffer {

      private:			
        std::unique_ptr<E[]> buffer;
        size_t m_size = 0;			
        const size_t m_capacity;
        size_t insertionIndex = 0;
        size_t extractionIndex = 0;
        bool m_destructive = false;
        std::mutex buffer_mutex;

      public:
        // CONSTRUCTOR
        CircularBuffer(size_t capacity = 0) :
          buffer(std::unique_ptr<E[]>(new E [capacity])), m_capacity(capacity)
        {
          ;
        }

        // DESTRUCTOR
        ~CircularBuffer() {
          ;
        }

        // MANIPULATORS
        /**
         * Thread-safe operation.
         * @return true if the given element could be inserted in the buffer.
         */
        bool put(E element) {		
          std::lock_guard<std::mutex> lock(buffer_mutex);

          bool canBeInserted = !isFull() || isDestructive();

          if(canBeInserted) {
            if(isFull()) {
              if(isDestructive())
                extractionIndex = incrementIndex(extractionIndex);
            } else {
              ++m_size;
            }
            buffer[insertionIndex] = element;					
            insertionIndex = incrementIndex(insertionIndex);
          }

          return canBeInserted;
        }
        /** 
         * Non thread -safe operation
         */
        void setDestructive(bool destructive) {
          m_destructive = destructive;
        }

        //ACCESORS
        /** 
         * Thread-safe operation.
         * @return true if the ring buffer was not empty and puts the extracted
         * element in the "element" output paramenter.
         */
        bool get(E& /*out*/ element) {
          std::lock_guard<std::mutex> lock(buffer_mutex);
          if(isEmpty()) {
            return false;
          } else {
            element = buffer[extractionIndex];
            extractionIndex = incrementIndex(extractionIndex);
            --m_size;
            return true;
          }
        }

        /** 
         * Non thread -safe operation
         */
        size_t getCapacity() {
          return m_capacity;
        }

        /** 
         * Non thread -safe operation
         */
        size_t getSize() {
          return m_size;
        }

        /** 
         * Non thread -safe operation
         */
        bool isEmpty() {
          return m_size == 0;
        }

        /** 
         * Non thread -safe operation
         */
        bool isFull() {
          return m_capacity == m_size;
        }

        /** 
         * Non thread -safe operation
         */
        bool isDestructive(){
          return m_destructive;
        }

        /** 
         * Non thread -safe operation
         */
        friend std::ostream& operator<< 
          (std::ostream& outputStream, const CircularBuffer& circularBuffer)  {
            size_t capacity = circularBuffer.m_capacity;
            size_t size = circularBuffer.m_size;
            size_t insertionIndex = circularBuffer.insertionIndex;
            size_t extractionIndex = circularBuffer.extractionIndex;

            outputStream << "- insertionIndex at " << insertionIndex << std::endl;
            outputStream << "- extractionIndex at " << extractionIndex << std::endl;
            outputStream << "- size: " << size << std::endl;
            outputStream << "- capacity: " << capacity << std::endl;
            outputStream << "[";
            if(size > 0) {
              size_t i = extractionIndex;
              outputStream << circularBuffer.buffer[i++];
              for(; i != insertionIndex; i = incrementIndex(i))
                outputStream << ", " << circularBuffer.buffer[i];					
            }
            outputStream << "]" << std::endl;

            return outputStream;
          }

      private:
        size_t incrementIndex(size_t indexValue) {
          return (indexValue + 1) % this->m_capacity;
        }

    };
}


#endif
