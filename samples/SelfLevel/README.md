# Self Level

This sample code demonstrates how to connect to a Sphero and perform the self level command.
The connection is initiated by calling 

        [[RKRobotProvider sharedRobotProvider] openRobotConnection];        

This call into the RKRobotProvider singleton initiates the connection to a Sphero. Once the connection is opened and communications a verified ``RKDeviceConnectionOnlineNotification`` is posted for success, and ``RKDeviceConnectionOfflineNotification`` is posted on failure. In the handler for the ``RKDeviceConnectionOnlineNotification`` notification. 






When the application exits the connection is closed with the following line of code.

    [[RKRobotProvider sharedRobotProvider] closeRobotConnection];





