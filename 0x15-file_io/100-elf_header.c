#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_magic(unsigned char e_ident[EI_NIDENT]);
void print_class(unsigned char e_ident_class);
void print_data(unsigned char e_ident_data);
void print_osabi(unsigned char e_ident_osabi);
void print_type(Elf64_Half e_type);

/**
 * print_error - prints an error message to stderr.
 * @msg: the error message to print.
 */

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *ehdr)
{
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", ehdr->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

    printf("  Class:                             ");
    switch (ehdr->e_ident[EI_CLASS])
    {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Data:                              ");
    switch (ehdr->e_ident[EI_DATA])
    {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Version:                           %d\n", ehdr->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (ehdr->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM_AEABI: printf("ARM EABI\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (ehdr->e_type)
    {
        case ET_NONE: printf("NONE (None)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Entry point address:               %lx\n", ehdr->e_entry);

    printf("\n");
}

/**
 * main - displays the information contained in the ELF header at
 * the start of an ELF file.
 * @argc: number of arguments passed to the program.
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure.
 */


int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr ehdr;

    if (argc != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error: Cannot read file");

    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
        print_error("Error: Cannot read ELF header");

    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0)
        print_error("Error: Not an ELF file");

    printf("Magic:   ");
    print_magic(ehdr.e_ident);
    printf("Class:                             ");
    print_class(ehdr.e_ident[EI_CLASS]);
    printf("Data:                              ");
    print_data(ehdr.e_ident[EI_DATA]);
    printf("Version:                           %d\n", ehdr.e_ident[EI_VERSION]);
    printf("OS/ABI:                            ");
    print_osabi(ehdr.e_ident[EI_OSABI]);
    printf("ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);
    printf("Type:                              ");
    print_type(ehdr.e_type);
    printf("Entry point address:               0x%lx\n", ehdr.e_entry);

    if (close(fd) == -1)
        print_error("Error: Cannot close file");

    return 0;
}
