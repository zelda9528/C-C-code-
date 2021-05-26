#include<iostream>
#include<vector>

using namespace std;

//��ɢ��

//������Ľ��
template<class V>
struct HashNode {

	V _val;
	HashNode<V>* _next;


	HashNode(const V& val)
		:_val(val)
		,_next(nullptr)
	{}

};

//��ϣ��ǰ������
template<class K, class V, class KeyOfValue>
class HashTable;

//��ϣ��ĵ�����
//��װ������Ľ��
template<class K,class V,class KeyOfValue>
struct HashIterator{
	typedef HashIterator<K, V, KeyOfValue> Self;
	typedef HashTable<K, V, KeyOfValue> HT;
	//��Ա�����ָ��  ��ϣ��ָ��
	typedef HashNode<V> Node;

	HT* _hptr;
	Node* _node;

	HashIterator(Node* node,HT* hptr):_node(node),_hptr(hptr)
	{}

	V& operator*()
	{
		return _node->_val;
	}
	V* operator->()
	{
		return &_node->_val;
	}
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}
	Self& operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			//������һ���ǿ�����ĵ�ͷ���
			//���㵱ǰ�ڵ��ڹ�ϣ���е�λ��
			KeyOfValue kov;
			size_t idx = kov(_node->_val) % _hptr->_ht.size();
			//����һ����ϣλ�ÿ�ʼ����
			++idx;
			for (; idx < _hptr->_ht.size(); idx++)
			{
				if (_hptr->_ht[idx])
				{
					_node = _hptr->_ht[idx];
					break;
				}
			}
			//��Ч����������	
			if (idx == _hptr->_ht.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}

};

template<class K,class V,class KeyOfValue>
class HashTable {
public:
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyOfValue> iterator;
	//�ѵ�������������Ԫ��
	template<class K, class V, class KeyOfValue>
	friend struct HashIterator;

	HashTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//��һ����ЧԪ�ص�λ��
		for (size_t i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
				return iterator(_ht[i], this);
		}
		return iterator(nullptr,this);
	}
	iterator end()
	{
		return iterator(nullptr, this);	
	}



	pair <iterator, bool> insert(const V& val)
	{
		//0.�������
		checkCapacity();
		//1.����hashλ��
		KeyOfValue kov;
		size_t idx = kov(val) % _ht.size();
		//2.����
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
			{
				//key���ڣ�����ʧ��
				//return false;
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}
		//3.����:ͷ��
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;

		//return true;
		return make_pair(iterator(cur, this), true);
	}

	void checkCapacity()
	{
		//��ɢ�У�����ЧԪ�ظ������ڹ�ϣ����ʱ�����������ӵ���1ʱ����������
		//��������=��ЧԪ�ظ���/��ϣ����
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;
			//����������
			vector<Node*> newHT(newC);

			KeyOfValue kov;
			//�����ɱ�
			for (size_t i = 0; i < _ht.size(); i++)
			{
				Node* cur = _ht[i];
				//����������
				while (cur)
				{
					Node* next = cur->_next;
					//������λ��
					size_t idx = kov(cur->_val ) % newHT.size();
					//ͷ��

					cur->_next = newHT[idx];
					newHT[idx] = cur;

					cur = next;
				}
				//�ɱ��ÿ�
				_ht[i] = nullptr;
			}
			swap(_ht, newHT);
		}
	}

	Node* Find(const K& key)
	{}	
	bool Eraser(const K& key)
	{}


private:
	//ָ������
	vector<Node*> _ht;
	int _size;
};



//ģ��ʵ��Set
template<class K>
class Set {
	struct SetKeyOfValue {
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename HashTable<K, K, SetKeyOfValue>::iterator iterator;
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

	bool insert(const K& key)
	{
		return _ht.insert(key);
	}

private:
	HashTable<K, K, SetKeyOfValue> _ht;
};


//ģ��ʵ��Map
template<class K,class V>
class Map
{	
	struct MapKeyOfValue {
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue>::iterator iterator;

	pair<iterator, bool>insert(const pair<K,V>& val)
	{
		return _ht.insert(val);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.insert(make_pair(key,V()));
		return ret.first->second;
	}
	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue> _ht;

};

void test()
{
	Map<int, int> m;
	m.insert(make_pair(1,1));
	m[10] = 10;
	m[20] = 20;
	m[30] = 30;


	Map<int,int>::iterator it=m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << " ";
		++ it;
	}
	cout << endl;

	for (const auto& e : m)
	{
		cout << e.first << "--->"<<e.second<<" ";
	}
	cout << endl;
}


//void test()
//{
//	Set<int> s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(4);
//	s.insert(7);
//	s.insert(9);
//	s.insert(11);
//	s.insert(44);
//	s.insert(55);
//	s.insert(16);
//	s.insert(17);
//	s.insert(13);
//
//	Set<int>::iterator it=s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++ it;
//	}
//	cout << endl;
//
//	for (const auto& e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

int main()
{
	test();
	return 0;
}