#include "movie.h"
#include "util.h"
#include <iomanip>
#include <sstream>

using namespace std;

Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) :
    Product("movie", name, price, qty),
    genre_(genre),
    rating_(rating)
{
}

Movie::~Movie(){}

/**
 * Returns the appropriate keywords that this product should be associated with
 */
std::set<std::string> Movie::keywords() const
{
    //create set with keywords from name
    set<std::string> words(parseStringToWords(name_));

    //insert rest of keywords that we take as is
    words.insert(convToLower(genre_));

    return words;   

}

/**
 * Returns a string to display the product info for hits of the search
 */
std::string Movie::displayString() const
{
    std::stringstream ss;
    ss << name_ << "\n";
    ss << "Genre: " << genre_ << " Rating: " << rating_ << "\n";
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.";
    return ss.str();
}

/**
 * Outputs the product info in the database format
 */
void Movie::dump(std::ostream& os) const
{
    //dump the product version first and then add category specific
    Product::dump(os);
    os << genre_ << "\n" << rating_ << endl;
}