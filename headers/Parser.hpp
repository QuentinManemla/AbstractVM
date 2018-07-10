/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <qmanamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 19:19:54 by root              #+#    #+#             */
/*   Updated: 2018/07/10 16:23:49 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "OperandFactory.hpp"

class Parser {
public:
    Parser();
    ~Parser();

    void                runParser( std::list<std::string>& operations );
    eOperandType        getOperandValue( std::string operandType );

    void                push( std::string line );
    void                pop( void );
    void                dump( void );
    void                assert( std::string line );

    void                add( void );
    void                mul( void );
    void                div( void );

    // !EXCEPTIONS 
    class PopOnEmptyStack : public std::exception {
        public:
            PopOnEmptyStack( std::string line );
            ~PopOnEmptyStack() _NOEXCEPT;
        private:
            virtual const char *what() const throw();
            std::string _errMsg;
    };
private:
    std::list<IOperand const *> _stack;
    OperandFactory              _factory;

    int                         _lineCount;
};

#endif //!PARSER_HPP
