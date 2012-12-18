#include "log.h"

LOG &LOG::GetInstance ()
{
	static LOG theSingleInstance;
	return theSingleInstance;
}

LOG::LOG ()
{
	log_file = fopen ("error.log", "w");
}

LOG::~LOG ()
{
	fclose(log_file);
}

void	LOG::WriteStringToLog (char *fmt, ...)
{
	va_list		ap;
	char		format[STRING_LENGTH];
	int			count = 0;
	int			i, j;
	char		c;
	double		d;
	unsigned	u;
	char		*s;
	void		*v;

	va_start(ap, fmt);

	while (*fmt)
	{
		for (j = 0; fmt[j] && fmt[j] != '%'; j++)
			format[j] = fmt[j];

		if (j)
		{
			format[j] = '\0';
			count += fprintf(log_file, format);
			fmt += j;
		}
		else
		{
			for (j = 0; !isalpha(fmt[j]); j++)
			{
				format[j] = fmt[j];
			
				if (j && fmt[j] == '%')
					break;
			}

			format[j] = fmt[j];
			format[j + 1] = '\0';
			fmt += j + 1;

			switch (format[j])
			{
				case 'd':
				case 'i':
					i = va_arg(ap, int);
					count += fprintf(log_file, format, i);
					break;
				case 'o':
				case 'x':
				case 'X':
				case 'u':
					u = va_arg(ap, unsigned);
					count += fprintf(log_file, format, u);
					break;
				case 'c':
					c = (char) va_arg(ap, int);
					count += fprintf(log_file, format, c);
					break;
				case 's':
					s = va_arg(ap, char *);
					count += fprintf(log_file, format, s);
					break;
				case 'f':
				case 'e':
				case 'E':
				case 'g':
				case 'G':
					d = va_arg(ap, double);
					count += fprintf(log_file, format, d);
					break;
				case 'p':
					v = va_arg(ap, void *);
					count += fprintf(log_file, format, v);
					break;
				case 'n':
					count += fprintf(log_file, "%d", count);
					break;
				case '%':
					count += fprintf(log_file, "%%");
					break;
				default:
					fprintf (log_file, "Invalid format specifier in log().\n");
					break;
			}
		}
	}
  
	va_end(ap);
}