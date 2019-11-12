# USB Data Transfer

This project tries to transfer data between two computers through USB in the situation where it is not possible to restore the state of the system.


Read simple output example messages in /var/log/messages

to install...

make

insmod cp210x.ko

tail -n 1 /var/log/messages

rmmod cp210x

tail -n 1 /var/log/messages


#steps for any Linux device driver may be repeated:

    Build the driver (.ko file) by running make
    Load the driver using insmod
    List the loaded modules using lsmod
    Unload the driver using rmmod

#useful links: 
    https://www.kernel.org/doc/html/v4.16/driver-api/usb/usb3-debug-port.html
    http://www.gaw.ru/pdf/interface/usb/USB%203%200_english.pd
    https://github.com/torvalds/linux/blob/master/drivers/usb/early/xhci-dbc.c

