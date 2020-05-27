/*
 * Copyright 2013-2020 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Original source is copyright 2010 - 2011. Alexey Tsoy.
 * http://sourceforge.net/projects/interpreter11/
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef ARX_UTIL_CMDLINE_COMMANDLINEEXCEPTION_H
#define ARX_UTIL_CMDLINE_COMMANDLINEEXCEPTION_H

#include <stdexcept>

#include "platform/Platform.h"

namespace util { namespace cmdline {

class error : public virtual std::runtime_error {
	
public:
	
	typedef enum {
		no_exception,
		invalid_value,
		invalid_arg_count,
		already_exists,
		cmd_not_found,
		invalid_cmd_syntax,
	} exception_code;
	
	error(exception_code c, const std::string & message)
		: std::runtime_error(message), m_code(c) { }
	
	explicit error(exception_code c)
		: std::runtime_error(default_message(c)), m_code(c) { }
	
	static std::string default_message(exception_code c) {
		switch(c) {
			case no_exception:       return "uninitialized exception";
			case invalid_value:      return "the syntax is incorrect";
			case invalid_arg_count:  return "invalid arguments count";
			case already_exists:     return "command already exists";
			case cmd_not_found:      return "command not found";
			case invalid_cmd_syntax: return "commands must start with a dash (-)";
		}
		arx_unreachable();
	}
	
	exception_code code() const { return m_code; }
	
private:
	
	exception_code m_code;
	
};

} } // namespace util::cmdline

#endif // ARX_UTIL_CMDLINE_COMMANDLINEEXCEPTION_H
