#include <iostream>


class BlogPost {

private:
    std::string authorName;
    std::string title;
    std::string text;
    std::string publicationDate;

public:
    BlogPost(std::string a, std::string b, std::string c, std::string d) {
        authorName = a;
        title = b;
        text = c;
        publicationDate = d;
    }

    std::string post() {         /* toString lehet más nevű is*/
        std::string name = title + " titled by " + authorName + " posted at " + publicationDate + "\n" + text + "\n";
        return name;
    };
};

int main() {

    BlogPost ob1 ("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet", "2000.05.04.");
    BlogPost ob2 ("Tim Urban", "Wait but why", "A popular long-form, stick-figure-illustrated blog about almost everything.", "2010.10.10.");
    BlogPost ob3 ("William Turton", "One Engineer Is Trying to Get IBM to Reckon With Trump", "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.", "2017.03.28.");


    std::cout<< ob1.post() << ob2.post() << ob3.post() << std::endl;
    //std::cout << "" << std::endl;
    return 0;


    /*
Create a BlogPost class that has
an authorName
a title
a text
a publicationDate
Create a few blog post objects:
"Lorem Ipsum" titled by John Doe posted at "2000.05.04."
Lorem ipsum dolor sit amet.
"Wait but why" titled by Tim Urban posted at "2010.10.10."
A popular long-form, stick-figure-illustrated blog about almost everything.
"One Engineer Is Trying to Get IBM to Reckon With Trump" titled by William Turton at "2017.03.28."
Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention.
When I asked to take his picture outside one of IBM’s New York City offices,
he told me that he wasn’t really into the whole organizer profile thing.
 */


}