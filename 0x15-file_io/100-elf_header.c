#include "main.h"
#include <string.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 64

void print_error(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

void print_elf_header(Elf64_Ehdr *ehdr)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr->e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d%s\n", ehdr->e_ident[EI_VERSION], ehdr->e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("  OS/ABI:                            %d\n", ehdr->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n", ehdr->e_type);
	printf("  Entry point address:               %lx\n", ehdr->e_entry);
	printf("  Start of program headers:          %ld (bytes into file)\n", ehdr->e_phoff);
	printf("  Start of section headers:          %ld (bytes into file)\n", ehdr->e_shoff);
	printf("  Flags:                             0x%x\n", ehdr->e_flags);
	printf("  Size of this header:               %d (bytes)\n", ehdr->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n", ehdr->e_phentsize);
	printf("  Number of program headers:         %d\n", ehdr->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n", ehdr->e_shentsize);
	printf("  Number of section headers:         %d\n", ehdr->e_shnum);
	printf("  Section header string table index: %d\n", ehdr->e_shstrndx);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr;
	ssize_t n;

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1 )
	{
		print_error("Can't open file");
	}

	n = read(fd, &ehdr, sizeof(ehdr));

	if (n != sizeof(ehdr))
	{
		print_error("Error: Cannot read ELF header");
	}

	print_elf_header(&ehdr);

	close(fd);
	return (0);
}
