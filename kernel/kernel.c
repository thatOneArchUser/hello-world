//idk why tf i did this

typedef unsigned char u8;

static inline unsigned char inb(unsigned short port) {
    unsigned char result;
    asm volatile("inb %w1, %b0" : "=a" (result) : "Nd" (port));
    return result;
}

static inline void outb(unsigned short port, unsigned char data) {
    asm volatile("outb %b0, %w1" :: "a"(data), "Nd" (port));
}

static inline void putc(char c, int offset) {
    volatile u8 *vidmem = (u8 *) 0xB8000;
    vidmem[offset] = c;
    vidmem[offset + 1] = 0x0F;
}

static inline void set_cursor(int offset) {
    offset /= 2;
    outb(0x3D4, 14);
    outb(0x3D5, (u8) (offset >> 8));
    outb(0x3D4, 15);
    outb(0x3D5, (u8) (offset & 0xFF));
}

static inline int get_cursor() {
    outb(0x3D4, 14);
    int offset = inb(0x3D5) << 8;
    outb(0x3D4, 15);
    offset += inb(0x3D5);
    return offset * 2;
}

static void print_char(char c) {
    int offset = get_cursor();
    putc(c, offset);
    offset += 2;
    set_cursor(offset);
}

static void print_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i]);
    }
}

void kmain() {
    print_string("hello world");
    for (;;);
}