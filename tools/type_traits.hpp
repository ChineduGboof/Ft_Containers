/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:57:15 by cegbulef          #+#    #+#             */
/*   Updated: 2023/06/18 12:16:20 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
	
template <bool, typename T>
struct enable_if {};

/**
 * @brief Type trait for conditional enablement.
 *
 * This struct provides a conditional enablement based on a compile-time boolean condition.
 * The primary template is empty, while the specialization with a true condition defines a nested type 'type' as 'T'.
 */

template <typename T>
struct enable_if<true, T> { typedef T type; };

/**
 * @brief Type trait for checking integral types.
 *
 * This struct template checks if a given type is an integral type.
 * The static constant 'value' is set to 'false' for the primary template.
 * Specializations are provided for various integral types, where the 'value' is set to 'true'.
 */

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
