bool Parser::is_white_space (const char& symbol)
{
    return (symbol == '\n' or symbol == ' ' or symbol == 9 or symbol == 11 or symbol == '\0') ? true : false;
}

bool Parser::is_left_parenthese (const char& symbol)
{
    return (symbol == '(');
}
bool Parser::is_right_parenthese (const char& symbol)
{
    return (symbol == ')');
}

bool Parser::is_left_chevron (const char& symbol)
{
    return (symbol == '<');
}
bool Parser::is_right_chevron (const char& symbol)
{
    return (symbol == '>');
}

bool Parser::is_left_brace (const char& symbol)
{
    return (symbol == '{');
}

bool Parser::is_right_brace (const char& symbol)
{
    return (symbol == '}');
}

bool Parser::is_left_bracket (const char& symbol)
{
    return (symbol == '[');
}

bool Parser::is_right_bracket (const char& symbol)
{
    return (symbol == ']');
}

bool Parser::is_comma (const char& symbol)
{
    return (symbol == ',');
}

bool Parser::is_semicolon (const char& symbol)
{
    return (symbol == ';');
}

bool Parser::is_colon (const char& symbol)
{
    return (symbol == ':');
}

Parser::Parser(const String& str):m_str(str) 
{
}


void Parser::parse_code()
{
    String bar ;
    for(int i = 0;i <= m_str.size() ;++i) {
            if(m_str[i] >= 'A' && m_str[i] <= 'z' ) {
                bar.push_back( m_str[i]);
            } 
            else {
                if(bar.size() > 0) {      
                    tokens.push_back(bar);
                }
                bar.clear();
            }
        }
}

vector<String> Parser::get_tokens() const
{
    return tokens;
}
