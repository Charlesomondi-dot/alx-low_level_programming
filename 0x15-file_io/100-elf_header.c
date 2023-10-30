#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_header(Elf64_Ehdr *header) {
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%02x", header->e_ident[i]);
if (i < EI_NIDENT - 1) {
printf(" ");
}
}
printf("\n");
printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:                              %d\n", header->e_type);
printf("  Entry point address:               %lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return 98;
}

int fd = open(argv[1], O_RDONLY);
if (fd == -1) {
perror("open");
return 98;
}

Elf64_Ehdr header;
ssize_t num_bytes = read(fd, &header, sizeof(Elf64_Ehdr));
if (num_bytes != sizeof(Elf64_Ehdr)) {
fprintf(stderr, "Error reading ELF header\n");
close(fd);
return 98;
}

if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
fprintf(stderr, "Error: Not an ELF file\n");
close(fd);
return 98;
}
print_elf_header(&header);

close(fd);
return 0;
}
