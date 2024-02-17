
all: clean build_kernel compile_boot create_image

build_kernel:
    # Kompilering av kjernekomponenter
    gcc -m32 -fno-stack-protector -fno-builtin -c kernel.c -o kernel_custom.o
    gcc -m32 -fno-stack-protector -fno-builtin -c vga.c -o vga_custom.o
    gcc -m32 -fno-stack-protector -fno-builtin -c gdt.c -o gdt_custom.o

compile_boot:
    # Kompilering av oppstartsfilene
    nasm -f elf32 boot.asm -o boot_custom.o
    nasm -f elf32 gdt.asm -o gdt_setup.o

create_image:
    # Oppretting av systembilde
    ld -m elf_i386 -T link.ld -o kernel_custom.bin boot_custom.o kernel_custom.o vga_custom.o gdt_custom.o gdt_setup.o
    mv kernel_custom.bin ../arch/boot/kernel
    grub-mkrescue -o custom_os.iso arch/boot/
    rm -rf *.o
