/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:55 by marvin            #+#    #+#             */
/*   Updated: 2023/07/21 04:40:23 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

static size_t	ft_count_words_quotation(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\"')
		{
			i++;
			cnt++;
			while (s[i] && s[i] != '"')
				i++;
			if (!s[i])
				break ;
			i++;
		}
		if (s[i] == '\'')
		{
			i++;
			cnt++;
			while (s[i] && s[i] != '\'')
			{
				printf("\t%c\n", s[i]);
				i++;
			}
			if (!s[i])
				break ;
			i++;
			printf("\t%c\n", s[i]);
		}
		if (s[i])
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				cnt++;
		if (s[i])
			i++;
	}
	return (cnt);
}

static size_t	ft_count_wordlen_quotation(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (s[i] == '"')
	{
		if (!s[i + 1])
			return (0);
		while (s[++i] != '\"')
			;
		return (i);
	}
	if (s[i] == '\'')
	{
		if (!s[i + 1])
			return (0);
		while (s[++i] != '\'')
			;
		return (i);
	}
	else
		while (!(s[i] == c || s[i] == '\0'))
			i++;
	return (i);
}

static void	ft_word_cpy_quotation(char ***res, char const *s, size_t word_len,
					size_t rotation)
{
	size_t	i;

	i = 0;
	while (i < word_len)
	{
		res[0][rotation][i] = s[i];
		i++;
	}
	res[0][rotation][i] = '\0';
}

static char	**ft_memory_manager_quotation(char **res, size_t rotation)
{
	while (rotation > 0)
	{
		rotation--;
		free(res[rotation]);
	}
	free(res);
	return (NULL);
}

char	**ft_split_quotation(char const *s, char c)
{
	size_t		word_cnt;
	size_t		word_len;
	size_t		rotation;
	char		**res;

	word_cnt = ft_count_words_quotation(s, c);
	printf("-----------> %zu\n", word_cnt);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	rotation = -1;
	while (++rotation < word_cnt)
	{
		while (*s == c || *s == '\0')
			s++;
		printf("\t\t\t\t%s\n", s);
		word_len = ft_count_wordlen_quotation(s, c);
		printf("\t\tword_len = %zu\n", word_len);
		res[rotation] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (res[rotation] == NULL)
			return (ft_memory_manager_quotation(res, rotation));
		ft_word_cpy_quotation(&res, s, word_len, rotation);
		s = s + word_len;
	}
	res[rotation] = NULL;
	return (res);
}

// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	size_t idx = 0;
// 	char **res;
// 	(void)ac;
// 	// (void)av;
// 	// const char *str = "awk '{count++}END{print count}'";
// 	// char *str = "\"\"";
// 	// char *str = "\" awk asd asd a\"sd  \"";
// 	printf("\n[%s]\n\n", av[1]);
// 	res = ft_split_quotation(av[1], ' ');
// 	while (res[idx])
// 	{
// 		printf("[%s]\n", res[idx]);
// 		idx++;
// 	}
// }

// /*
// 		// printf("%s\n", s);
// 		// printf("%zu\n", word_len);
// 		// printf("\n");
// 		res[rotation] = (char *)malloc(sizeof(char) * (word_len + 1));
// 		ft_word_cpy(&res[rotation], s, word_len);
// 		s = s + word_len;
// 		// puts("-------------------------------------------");
// 		puts(res[rotation]);
// 		// puts("-------------------------------------------");
// */
