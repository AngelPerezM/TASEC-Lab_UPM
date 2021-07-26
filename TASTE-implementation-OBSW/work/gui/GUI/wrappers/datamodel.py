#!/usr/bin/python

import DV

FVname = "gui"

tc = {}
tm = {}
errCodes = {}

tm["Attitude_Data"] = {'nodeTypename': 'ATT-GUI', 'type': 'SEQUENCE', 'id': 'Attitude_Data', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'gps', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'mode', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["not-seen", "no-fix", "two-dims", "three-dims"], "valuesInt": {"not-seen": 0, "no-fix": 1, "two-dims": 2, "three-dims": 3}},
{'nodeTypename': '', 'type': 'REAL', 'id': 'date_and_time', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'ept', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'latitude', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'epy', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'longitude', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'epx', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'altitude', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'epv', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'course', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'epd', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'speed', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'eps', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'climb', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'epc', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'gps_date_time', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'INTEGER', 'id': 'day', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -2147483648, 'maxR': 2147483647},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'month', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -2147483648, 'maxR': 2147483647},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'year', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -2147483648, 'maxR': 2147483647},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'hour', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -2147483648, 'maxR': 2147483647},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'minute', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -2147483648, 'maxR': 2147483647},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'second', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -2147483648, 'maxR': 2147483647}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'imu', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'mgt_mgauss', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'x_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'y_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'z_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'accel_mg', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'x_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'y_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'z_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'gyro_mdps', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'x_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'y_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'z_axis', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000}]},
{'nodeTypename': '', 'type': 'REAL', 'id': 'temp_celsius', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'mgt_valid', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'acc_valid', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'gyro_valid', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'temp_valid', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}]}]}
tm["Environmental_Data"] = {'nodeTypename': 'ENV-GUI', 'type': 'SEQUENCE', 'id': 'Environmental_Data', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'pressure_sensor_1', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'pressure_mbar', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'temperature_celsius', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'pressure_sensor_2', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'pressure_mbar', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'temperature_celsius', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'anemometer', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'INTEGER', 'id': 'global_counter', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': 0, 'maxR': 18446744073709551615},
{'nodeTypename': '', 'type': 'REAL', 'id': 'temperature_celsius', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'temperature_validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'heater', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'power_watts', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}]}]}
tm["HTL_Data"] = {'nodeTypename': 'HTL-GUI', 'type': 'SEQUENCE', 'id': 'HTL_Data', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'state', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["a1", "a2", "f1", "f2", "f3", "error"], "valuesInt": {"a1": 0, "a2": 1, "f1": 2, "f2": 3, "f3": 4, "error": 5}},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'heater', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'power_watts', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}]},
{'nodeTypename': '', 'type': 'REAL', 'id': 'delta_T', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'pt1000s', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'aire_abajo', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'aire_arriba', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'placa_abajo', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'placa_arriba', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'infinito', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'exterior', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'SEQOF', 'id': 'validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minSize': 6, 'maxSize': 6, 'seqoftype':{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'validity', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}
}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'tc74s', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'x_positive', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'x_negative', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'y_positive', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'y_negative', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'z_techo', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'SEQOF', 'id': 'validity', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'minSize': 5, 'maxSize': 5, 'seqoftype':{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'validity', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, 'values':["valid", "invalid"], "valuesInt": {"valid": 0, "invalid": 1}}
}]}]}
tc["send_telecommand"] = {'nodeTypename': 'TC', 'type': 'CHOICE', 'id': 'send_telecommand', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "choices":[{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'heater_commands', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'heater_of_HTL', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'heater', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, 'values':["heater-HTL", "heater-anemo"], "valuesInt": {"heater-HTL": 0, "heater-anemo": 1}},
{'nodeTypename': '', 'type': 'CHOICE', 'id': 'command', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "choices":[{'nodeTypename': '', 'type': 'REAL', 'id': 'power_manual', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'max_min', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, 'values':["max", "min"], "valuesInt": {"max": 0, "min": 1}}], "choiceIdx": {"power_manual": DV.power_manual_PRESENT,"max_min": DV.max_min_PRESENT}}]},
{'nodeTypename': '', 'type': 'SEQUENCE', 'id': 'config_of_HTL', 'isOptional': False, 'alwaysPresent': True, 'alwaysAbsent': False, "children":[{'nodeTypename': '', 'type': 'REAL', 'id': 'press_5km', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'press_10km', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'press_18km', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -339999999999999996123846586046231871488.00000000000000000000, 'maxR': 339999999999999996123846586046231871488.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'a1_duration_emergency_secs', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'a1_duration_max_secs', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'REAL', 'id': 'a2_duration_max_secs', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': -169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000, 'maxR': 169999999999999993883079578865998174333346074304075874502773119193537729178160565864330091787584707988572262467983188919169916105593357174268369962062473635296474636515660464935663040684957844303524367815028553272712298986386310828644513212353921123253311675499856875650512437415429217994623324794855339589632.00000000000000000000},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'f1_duration_secs', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': 0, 'maxR': 4294967295},
{'nodeTypename': '', 'type': 'INTEGER', 'id': 'f2_duration_secs', 'isOptional': True, 'alwaysPresent': False, 'alwaysAbsent': False, 'minR': 0, 'maxR': 4294967295}]}]},
{'nodeTypename': '', 'type': 'ENUMERATED', 'id': 'system_commands', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, 'values':["stop"], "valuesInt": {"stop": 0}}], "choiceIdx": {"heater_commands": DV.heater_commands_PRESENT,"system_commands": DV.system_commands_PRESENT}}
tc["setCurrentMode"] = {'nodeTypename': 'HTL-State', 'type': 'ENUMERATED', 'id': 'setCurrentMode', 'isOptional': False, 'alwaysPresent': False, 'alwaysAbsent': False, 'values':["a1", "a2", "f1", "f2", "f3", "error"], "valuesInt": {"a1": 0, "a2": 1, "f1": 2, "f2": 3, "f3": 4, "error": 5}}