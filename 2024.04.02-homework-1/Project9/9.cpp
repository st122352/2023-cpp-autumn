#include<iostream>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	void set(int a, int b, int w)
	{
		this->a = a;
		this->b = b;
		this->w = w;
	}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	///������� ������� ��������� �����
	void PrintMatrix();
	///������� ���� �����
	void PrintEdges();
	///��������� ������� ��������� �����
	void ReadMatrix(int vertexes, std::istream& stream);
	///��������� ���� �����
	void ReadEdges(int edges, std::istream& stream, bool haveweight = false);
	int vertexCount();
	void inputAdjencyList();

private:
	///������� ������� ��������� n*n � ������� � ������ ������� m
	void init();
	///������� ������� ��������� _vertexes*_vertexes
	void initMatrix();
	///������� ������� ������� � ������ ������� _edges
	void initEdges();
	void initMatrixFromEdges();
	void initEdgesFromMatrix();
	int getVertexesCountFromEdges();
	int getEdgesCountFromMatrix();
	///������� ������� ��������� � ������� � ������
	void dispose();
	///������� ������� ���������
	void disposeMatrix();
	///������� ������� � ������
	void disposeEdges();

	int _vertexes;
	int _edges;
	int** _matrix;
	SEdge* _edge;
};

int main(int argc, char* argv[])
{
	int v = 0;
	std::cin >> v;
	CGraph g(v, 0);
	g.inputAdjencyList();
	std::cout << g.vertexCount() << std::endl;
	g.PrintMatrix();
	return EXIT_SUCCESS;
}

CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edge(nullptr)
{
	init();
}

CGraph::~CGraph()
{
	dispose();
}

void CGraph::PrintMatrix()
{
	if (_matrix == nullptr)
	{
		if (_edge == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initMatrixFromEdges();
	}
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 1; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges()
{
	if (_edge == nullptr)
	{
		if (_matrix == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initEdgesFromMatrix();
	}
	for (int i = 0; i < _edges; ++i)
	{
		std::cout << _edge[i] << std::endl;
	}
}

void CGraph::ReadMatrix(int vertexes, std::istream& stream)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			stream >> _matrix[i][j];
		}
	}
	initEdgesFromMatrix();
}

void CGraph::ReadEdges(int edges, std::istream& stream, bool haveweight)
{
	_edges = edges;
	initEdges();
	for (int i = 0; i < _edges; ++i)
	{
		std::cin >> _edge[i].a >> _edge[i].b;
		if (haveweight)
		{
			std::cin >> _edge[i].w;
		}
	}
}

void CGraph::init()
{
	dispose();
	initMatrix();
	initEdges();
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::initEdges()
{
	if (_edges == 0)
	{
		return;
	}
	_edge = new SEdge[_edges];
}

void CGraph::initMatrixFromEdges()
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		_matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
	}
}

int CGraph::getEdgesCountFromMatrix()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			count += (_matrix[i][j] != 0);
		}
	}
	return count;
}

void CGraph::dispose()
{
	disposeMatrix();
	disposeEdges();
}

void CGraph::disposeMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::disposeEdges()
{
	if (_edge != nullptr)
	{
		delete[] _edge;
		_edge = nullptr;
	}
}

void CGraph::initEdgesFromMatrix()
{
	disposeEdges();
	_edges = getEdgesCountFromMatrix();
	initEdges();
	for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
	{
		for (int j = 0; j < _vertexes && k < _edges; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_edge[k++].set(i + 1, j + 1, _matrix[i][j]);
			}
		}
	}
}

int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edges; ++i)
	{
		res = (res > _edge[i].a ? res : _edge[i].a);
		res = (res > _edge[i].b ? res : _edge[i].b);
	}
	return res + 1;
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
	stream << edge.a << " " << edge.b;
	if (edge.w > 1)
	{
		stream << " " << edge.w;
	}
	return stream;
}

int CGraph::vertexCount()
{
	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}
	return _vertexes;
}

void CGraph::inputAdjencyList()
{
	for (int i = 0; i < vertexCount(); ++i)
	{
		int n = 0;
		std::cin >> n;
		while (n != 0)
		{
			int end = 0;
			std::cin >> end;
			_matrix[i][end - 1] = 1;
			--n;
		}
	}
}