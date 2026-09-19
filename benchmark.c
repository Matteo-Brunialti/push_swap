#include "push_swap.h"

/*
 * The optional benchmark mode (--bench) must display, after sorting:
 * The computed disorder (% with two decimals).
 * The name of the strategy used and its theoretical complexity class.
 * The total number of operations.
 * The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
 * rrr).
 * The benchmark output must be sent to stderr and only appear when the flag is
 * present.
 */

static int	count_digit(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa(int n)
{
	long long	long_n;
	int			i;
	char		*str;

	i = count_digit(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		long_n = -((long long)n);
	}
	else
		long_n = n;
	while (long_n)
	{
		i--;
		str[i] = '0' + (long_n % 10);
		long_n /= 10;
	}
	return (str);
}

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*sjoined;

	if (s1 == NULL || s2 == NULL)
		return (free(s1), free(s2), NULL);
	sjoined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sjoined)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		sjoined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sjoined[i + j] = s2[j];
		j++;
	}
	sjoined[i + j] = '\0';
	free(s1);
	free(s2);
	return (sjoined);
}

static char	*sos(char *s1)
{
	char	*seallocata;
	size_t	i;

	if (!s1)
		return (NULL);
	seallocata = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!seallocata)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		seallocata[i] = s1[i];
		i++;
	}
	seallocata[i] = '\0';
	return (seallocata);
}

static char	*disorder(float disorder_val)
{
	char	*percent;
	int		disorder_val_int;

	percent = malloc(sizeof(char) * 7);
	if (!percent)
		return (NULL);
	disorder_val_int = (int)(disorder_val * 10000);
	percent[4] = '0' + disorder_val_int % 10;
	disorder_val_int /= 10;
	percent[3] = '0' + disorder_val_int % 10;
	disorder_val_int /= 10;
	percent[1] = '0' + disorder_val_int % 10;
	disorder_val_int /= 10;
	percent[0] = '0' + disorder_val_int % 10;
	disorder_val_int /= 10;
	percent[2] = '.';
	percent[5] = '%';
	percent[6] = '\0';
	return (ft_strjoin(sos("[bench] disorder: "), percent));
}

static char	*strategy(t_options *options, float disorder)
{
	if (options->adaptive)
	{
		if (disorder < 0.2)
			return (ft_strjoin(sos("\n[bench] strategy: Adaptive / O(n2)\n"),
					sos("")));
		if (0.2 <= disorder && disorder < 0.5)
			return (ft_strjoin(sos("\n[bench] strategy: Adaptive / O(n√n)\n"),
					sos("")));
		if (disorder >= 0.5)
			return (ft_strjoin(sos("\n[bench] strategy: Adaptive "
									"/ O(n log n)\n"),
								sos("")));
	}
	else if (options->complex)
		return (ft_strjoin(sos("\n[bench] strategy: Complex / O(n log n)\n"),
				sos("")));
	else if (options->medium)
		return (ft_strjoin(sos("\n[bench] strategy: Medium / O(n√n)\n"),
				sos("")));
	else if (options->simple)
		return (ft_strjoin(sos("\n[bench] simple: Simple /  O(n2)\n"),
				sos("")));
	return (NULL);
}

static char	*operations(t_options *options)
{
	char	*line;

	line = ft_strjoin(sos("[bench] sa: "), ft_itoa(options->sa));
	line = ft_strjoin(line, ft_strjoin(sos(" sb: "), ft_itoa(options->sb)));
	line = ft_strjoin(line, ft_strjoin(sos(" ss: "), ft_itoa(options->ss)));
	line = ft_strjoin(line, ft_strjoin(sos(" sb: "), ft_itoa(options->sb)));
	line = ft_strjoin(line, ft_strjoin(sos(" pa: "), ft_itoa(options->pa)));
	line = ft_strjoin(line, ft_strjoin(sos(" pb: "), ft_itoa(options->pb)));
	line = ft_strjoin(line, ft_strjoin(sos("\n[bench] ra: "),
				ft_itoa(options->ra)));
	line = ft_strjoin(line, ft_strjoin(sos(" rb: "), ft_itoa(options->rb)));
	line = ft_strjoin(line, ft_strjoin(sos(" rr: "), ft_itoa(options->rr)));
	line = ft_strjoin(line, ft_strjoin(sos(" rra: "), ft_itoa(options->rra)));
	line = ft_strjoin(line, ft_strjoin(sos(" rrb: "), ft_itoa(options->rrb)));
	line = ft_strjoin(line, ft_strjoin(sos(" rrr: "), ft_itoa(options->rrr)));
	line = ft_strjoin(line, sos("\n"));
	return (line);
}

static char	*operations_total_ops(t_options *options)
{
	int		tot;
	char	*total_ops;

	tot = 0;
	tot += options->sa;
	tot += options->sb;
	tot += options->ss;
	tot += options->pa;
	tot += options->pb;
	tot += options->ra;
	tot += options->rb;
	tot += options->rr;
	tot += options->rra;
	tot += options->rrb;
	tot += options->rrr;
	total_ops = ft_strjoin(sos("[bench] total_ops: "), ft_itoa(tot));
	total_ops = ft_strjoin(total_ops, sos("\n"));
	return (total_ops);
}

int	benchmark(t_options *options, float disorder_val)
{
	char	*final;
	int		i;

	final = disorder(disorder_val);
	final = ft_strjoin(final, strategy(options, disorder_val));
	final = ft_strjoin(final, operations_total_ops(options));
	final = ft_strjoin(final, operations(options));
	if (!final)
		return (-1);
	i = 0;
	while (final[i])
		i++;
	write(2, final, i);
	return (0);
}
