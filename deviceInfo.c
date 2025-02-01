#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/netdevice.h>

static void print_network_devices(void)
{
    struct net_device* net_dev;

    // Print network devices info
    pr_info("Network Devices:\n");
    for_each_netdev(&init_net, net_dev) {
        pr_info("Name: %s, MTU: %d, Type: %d\n", net_dev->name, net_dev->mtu, net_dev->type);
    }
}

static int __init device_info_init(void)
{
    pr_info("Loading device_info module...\n");

	print_network_devices();

	return 0;
}

static void __exit device_info_exit(void)
{
    pr_info("Exiting device_info module...\n");
}

module_init(device_info_init);
module_exit(device_info_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kobe Gatti");
MODULE_DESCRIPTION("Starter Linux device info module");

