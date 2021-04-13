/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:11 by marvin            #+#    #+#             */
/*   Updated: 2021/04/12 17:59:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *num_filler(int size,  char **params) {
	int	*numbers;

	if (!(numbers = (int *)malloc(sizeof(int) * size)))
		return (0);
	while (*params)
	{
		*numbers = atoi(*params++);
		// printf("output: %d\n", atoi(*params++));
	}
	return (numbers);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return 0;
	num_filler(argc - 1, ++argv);
}

