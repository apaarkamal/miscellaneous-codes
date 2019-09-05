class Foo
{

};

class Compare
{
public:
	bool operator() (Foo, Foo)
	{
		return true;
	}
};

int main()
{
	std::priority_queue<Foo, std::vector<Foo>, Compare> pq;
	return 0;
}