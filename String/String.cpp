
// двойное двоеточие :: - это оператор разрешени€ видимости Scope Operator
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//			Constructor

String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}

String::String(const char str[]) :size(strlen(str) + 1), str(new char[size] {}) // в первую очередь в конструкторе  
{
	for (int i = 0; i < size; i++) this->str[i] = str[i];// заполн€ем пам€ть
	cout << "Constructor:\t" << this << endl;
}

String::String(const String& other) :String(other.str) // const можно проинициализировать только в заголовке
{
	cout << "CopyConsrtuctor:" << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str) // вот такую инициализацтию в заголовке 
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}


String::~String()
{
	delete[] str;
	cout << "Destructor" << this << endl;
}

// operators

String& String::operator=(const String& other)
{
	if (this == &other)return*this; // защита класса и объектов от нежданчика
	delete[] str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}



char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods:

void String::print()const
{
	cout << "Size: " << size << endl;
	cout << "Str:  " << str << endl;
}




String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i]; // оператор []  - они вычисл€ют адрес и разъименовывают элемент массива - 
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
