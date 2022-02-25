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

Parser::Parser(const std::string& file_name)
{
    fin.open(file_name);
    if (!fin.is_open())
    {
        std::cout << "couldn't open file" << std::endl;
        throw;
    }
}
Parser::~Parser()
{
    fin.close();
}

void Parser::parse_code()
{
    std::string line;
    std::string singleToken;

    while (!fin.eof())
    {
        line.clear();
        std::getline(fin, line);
        for (int i = 0; i <= line.size(); ++i)
        {
            if (is_left_parenthese(line[i]) or is_right_parenthese(line[i]
                                           or is_left_bracket(line[i]) or is_right_bracket(line[i])
                                           or is_left_brace(line[i]) or is_right_brace(line[i])
                                           or is_comma(line[i]) or is_semicolon(line[i]) or is_colon(line[i]))
                                           or is_left_chevron(line[i]) or is_right_chevron(line[i]))
            {
                if (!singleToken.empty())
                {
                    tokens.push_back(singleToken);
                }
                singleToken = line[i];
                tokens.push_back(singleToken);
                singleToken.clear();
            }
                    else if (! is_white_space(line[i]))
            {
                singleToken += line[i];
            }
            else
            {
                if (!singleToken.empty())
                {
                    tokens.push_back(singleToken);
                    singleToken.clear();
                }
            }
        }
    }
}

std::vector<std::string> Parser::get_tokens() const
{
    return tokens;
}
