void init_descriptor_tables();

struct gdt_entry_struct
{
	unsigned short low_limit;	//lower 16 bits of limit
	unsigned short low_base;	//lower 16 bits of base
	unsigned char mid_base;		//next 8 bits of base
	unsigned char access;		//access flags(for ring)
	unsigned char granularity;
	unsigned char high_base;	//last 8 bits of base
} __attribute__((packed));

typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct
{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

typedef struct gdt_ptr_struct gdt_ptr_t;

struct idt_entry_struct
{
	unsigned short low_base;
	unsigned short sel;
	unsigned char always0;
	unsigned char flags;
	unsigned short high_base;
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct
{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

extern void isr0 ();
extern void isr1 ();
extern void isr2 ();
extern void isr3 ();
extern void isr4 ();
extern void isr5 ();
extern void isr6 ();
extern void isr7 ();
extern void isr8 ();
extern void isr9 ();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();