#include <iostream>

class PostIt {

private:
    std::string backgroundColor;
    std::string text;
    std::string textColor;

public:
    PostIt(std::string a, std::string b, std::string c) {
        backgroundColor = a;
        text = b;
        textColor = c;
    }

    std::string toString(){         /* toString lehet más nevű is*/
        std::string name = "backgroundcolor: " + backgroundColor + " , text: " + text + " , textcolor: " + textColor;
        return name;
    };
};

int main()
{
    PostIt ob1 ("orange", "Idea 1", "blue");

    std::cout<< ob1.toString() << std::endl;


/*Create a PostIt class that has
a backgroundColor
a text on it
a textColor
Create a few example post-it objects:
an orange with blue text: "Idea 1"
a pink with black text: "Awesome"
a yellow with green text: "Superb!"*/



    return 0;
}