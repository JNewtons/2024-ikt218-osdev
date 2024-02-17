#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include <multiboot2.h>



struct CustomBootInfo {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first_tag;
};

int custom_kernel_main();

// Hovedfunksjon for oppstart, bruker det nye strukturnavnet
int main(uint32_t magic, struct CustomBootInfo *boot_info) {
    // Kall til den tilpassede hovedfunksjonen for kjerne
    return custom_kernel_main();
}