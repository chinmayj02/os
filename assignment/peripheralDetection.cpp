// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     /* launch a command and gets its output */
//     FILE *f = popen("mount | grep /dev/sda1", "r");
//     if (NULL != f)
//     {
//         /* test if something has been outputed by 
//            the command */
//         if (EOF == fgetc(f))
//         {
//             puts("/dev/sda1 is NOT mounted");
//         }
//         else
//         {
//             puts("/dev/sda1 is mounted");
//         }        
//         /* close the command file */
//         pclose(f);        
//     } 
//     return 0;
// }


#include <stdio.h>
#include <usb.h>
int main(){
    struct usb_bus *bus;
    struct usb_device *dev;
    usb_init();
    usb_find_busses();
    usb_find_devices();
    for (bus = usb_busses; bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            printf("Trying device %s/%s\n", bus->dirname, dev->filename);
            printf("\tID_VENDOR = 0x%04x\n", dev->descriptor.idVendor);
            printf("\tID_PRODUCT = 0x%04x\n", dev->descriptor.idProduct);
        }
    }
}