
extern void uart0_init(void);
extern void puts(char *str);
extern void puthex(unsigned int val);

int strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

void strcpy(char *dest, char *src)
{
	while ((*dest++ = *src++) != '\0');
}

int main(void)
{
	/* 0. ���ں����ô���: �ں������Ŀ�ʼ���ֻ�Ӵ��ڴ�ӡһЩ��Ϣ,�����ں�һ��ʼû�г�ʼ������ */
	uart0_init();
	while(1)
	{
	/* 1. ��NAND FLASH����ں˶����ڴ� */
		puts("ok.\n\r");
	}
	return -1;
}

