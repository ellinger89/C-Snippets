// THE 'MUTALBE' KEYWORD 
// IN THE CONTEXT OF PRIVATE CLASS MEMBERS THAT SHALL BE CHANGED ALTHOUGH 
// THEY ARE PART OF A CONST OBJECT OF THIS CLASS

class Entity {
private:
	// 3.) but now we want to manipulate this particular variable anyhow.
	// since this variable will be changed from within a method that 
	// promised not to change anything (~ method() const {}), the
	// variable must be explicitly marked as mutable
	mutable std::string mystring;
public:
	// ´2.) for a method to be called from such a const object,
	// the method must "promise" that it is not going to change anything
	std::string& getX() const
	{
		return mystring;
	}
	void setX(std::string someString) const
	{
		mystring = someString;
	}
};

int main() {

	// 1.) somehow you want an object that can not be changed
	const Entity obj;
	obj.setX("hubuduboo");

	// 4.) So now, allthough all the methods involved promised that they
	// will not change any members of the Entity-Class, those methods
	// can still set and return the member "mystring", because it was
	// explicitly marked as mutable
	std::string a;
	a = obj.getX();
	print(a);

	std::cin.get();
}