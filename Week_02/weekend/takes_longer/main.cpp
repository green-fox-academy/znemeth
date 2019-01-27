#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string quote("Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.");

    // When saving this quote a disk error has occured. Please fix it.
    // Add "always takes longer than" to the quote between the words "It" and "you" using the replace function

    std::string insert = "always takes longer than ";   /* amit be akarok illeszteni*/
    std::string from ="It";                             /* ahova be akarom illeszteni*/
    int pos = quote.find(from);                         /* definiálom h mennyi stringet illesztek*/

    quote.insert(pos+3, insert);

    std::cout << quote << std::endl;
    return 0;
}