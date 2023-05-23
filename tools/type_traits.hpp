/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:19:54 by gboof             #+#    #+#             */
/*   Updated: 2023/05/17 13:20:54 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
	
template <bool, typename T>
struct enable_if {};

template <typename T>
struct enable_if<true, T> { typedef T type; };

template <typename>
struct is_integral { static const bool value = false; };

template <>
struct is_integral<bool> { static const bool value = true; };

template <>
struct is_integral<char> { static const bool value = true; };

template <>
struct is_integral<signed char> { static const bool value = true; };

template <>
struct is_integral<unsigned char> { static const bool value = true; };

template <>
struct is_integral<wchar_t> { static const bool value = true; };

template <>
struct is_integral<short> { static const bool value = true; };

template <>
struct is_integral<unsigned short> { static const bool value = true; };

template <>
struct is_integral<int> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<long> { static const bool value = true; };

template <>
struct is_integral<unsigned long> { static const bool value = true; };

template <>
struct is_integral<long long> { static const bool value = true; };

template <>
struct is_integral<unsigned long long> { static const bool value = true; };

}

#endif
