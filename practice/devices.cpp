#include <stdio.h>
#include <string.h>
#include <libudev.h>

int main(void)
{
    struct udev *udev;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *dev_list_entry;

    /* create udev object */
    udev = udev_new();
    if (!udev) {
        fprintf(stderr, "Can't create udev\n");
        return 1;
    }

    /* create a list of the devices in the 'usb' subsystem */
    enumerate = udev_enumerate_new(udev);
    udev_enumerate_add_match_subsystem(enumerate, "usb");
    udev_enumerate_scan_devices(enumerate);
    devices = udev_enumerate_get_list_entry(enumerate);

    /* loop through the devices */
    udev_list_entry_foreach(dev_list_entry, devices) {
        const char *path;
        struct udev_device *dev;

        /* get the device's path and create a udev device object */
        path = udev_list_entry_get_name(dev_list_entry);
        dev = udev_device_new_from_syspath(udev, path);

        /* print device information */
        printf("Device Node Path: %s\n", udev_device_get_devnode(dev));
        printf("Product Name: %s\n", udev_device_get_sysattr_value(dev, "product"));
        printf("Vendor ID: %s\n", udev_device_get_sysattr_value(dev, "idVendor"));
        printf("Product ID: %s\n", udev_device_get_sysattr_value(dev, "idProduct"));

        /* free the device object */
        udev_device_unref(dev);
    }

    /* free the enumerate object */
    udev_enumerate_unref(enumerate);

    /* free the udev object */
    udev_unref(udev);

    return 0;
}