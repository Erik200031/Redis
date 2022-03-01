#include "parser.h"



Parser::Parser(const String& str):m_str(str) {};


void Parser::parse_code()
{
    String bar ;
    for(int i = 0;i <= m_str.size() ;++i) {
            /*if(m_str[i] !=' ') {
                bar.push_back( m_str[i]);
            } 
            else {
                if(bar.size() > 0) {      
                    tokens.push_back(bar);
                }
                bar.clear();
            }*/
            if( m_str[i]=='\n' || m_str[i]==' ' )
            {
                ++i;
                if(bar.size()!=0)
                {
                    tokens.push_back(bar);
                }
                bar.clear();
            }
            else{
                bar.push_back(m_str[i]);
            }
        }
}

vector<String> Parser::get_tokens() const
{
    return tokens;
}
