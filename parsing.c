/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:51:10 by skaur             #+#    #+#             */
/*   Updated: 2023/06/30 15:18:49 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char* my_strpbrk(const char* str, const char* chars) {
    const char* s = str;
    while (*s != '\0') {
        const char* c = chars;
        while (*c != '\0') {
            if (*s == *c) {
                return (char*)s;
            }
            c++;
        }
        s++;
    }
    return NULL;
}

char* my_strtok(char* str, const char* delim) {
    static char* buffer = NULL;
    if (str != NULL) {
        buffer = str;
    }

    if (buffer == NULL) {
        return NULL;
    }

    // Skip leading delimiters
    while (*buffer != '\0' && ft_strchr(delim, *buffer) != NULL) {
        buffer++;
    }

    char* token_start = buffer;
    char* token_end = my_strpbrk(buffer, delim);

    if (token_end != NULL) {
        *token_end = '\0';
        buffer = token_end + 1;
    } else {
        buffer = NULL;
    }

    return token_start;
}
