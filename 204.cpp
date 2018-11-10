/*
*   Copyright © 2018
*
*   Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
*
*   Double degree in Mathematics-Computer engineering.
*   Complutense university, Madrid.
*
*/

#ifndef bintree_eda_h
#define bintree_eda_h

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

template <class T>
class bintree {
protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vacío (no existe).
	*/
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		TreeNode(T const& e) : elem(e), left(nullptr), right(nullptr) {}
		T elem;
		Link left, right;
	};

	// puntero a la raíz del árbol
	Link raiz;

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

public:
	// árbol vacío
	bintree() : raiz(nullptr) {}

	// árbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// árbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignación y destructora por defecto

	// consultar si el árbol está vacío
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la raíz
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree<T>(raiz->left);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree(raiz->right);
	}


	// recorridos

	std::vector<T> preorder() const {
		std::vector<T> pre;
		preorder(raiz, pre);
		return pre;
	}

	std::vector<T> inorder() const {
		std::vector<T> in;
		inorder(raiz, in);
		return in;
	}

	std::vector<T> postorder() const {
		std::vector<T> post;
		postorder(raiz, post);
		return post;
	}

	std::vector<T> levelorder() const {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem);
				if (sig->left != nullptr)
					pendientes.push(sig->left);
				if (sig->right != nullptr)
					pendientes.push(sig->right);
			}
		}
		return levels;
	}

protected:
	static void preorder(Link a, std::vector<T> & pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);
		}
	}

	static void inorder(Link a, std::vector<T> & in) {
		if (a != nullptr) {
			inorder(a->left, in);
			in.push_back(a->elem);
			inorder(a->right, in);
		}
	}

	static void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left, post);
			postorder(a->right, post);
			post.push_back(a->elem);
		}
	}

public:
	// iterador que recorre el árbol en inorden
	class const_iterator {
	public:
		T const& operator*() const {
			if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
			return ptr->elem;
		}

		T const* operator->() const {
			return &operator*();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(*this == other);
		}

		const_iterator & operator++() {  // ++ prefijo
			next();
			return *this;
		}

	private:
		friend class bintree;
		Link ptr;
		std::stack<Link> ancestros;

		// constructores privados
		const_iterator() : ptr(nullptr) {}
		const_iterator(Link raiz) { ptr = first(raiz); }

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left != nullptr) {
					ancestros.push(act);
					act = act->left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr->right != nullptr) { // primero del hijo derecho
				ptr = first(ptr->right);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				ptr = nullptr;
			}
			else { // podemos retroceder
				ptr = ancestros.top();
				ancestros.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(raiz);
	}
	const_iterator end() const {
		return const_iterator();
	}

	bool bienDecorado(int &numAdornos)
	{
		if (empty())
		{
			//No se debe poder entrar aquí
		}
		if (left().empty() && right().empty()) //Estamos en una hoja
		{
			if (root() == '*') numAdornos = 1;
			else               numAdornos = 0;

			return true;
		}
		else
		{
			int adornosDcha, adornosIzq;

			bool decoradoIzq  = left().bienDecorado(adornosIzq);
			bool decoradoDcha = right().bienDecorado(adornosDcha);

			numAdornos = adornosDcha + adornosIzq;

			return decoradoIzq && decoradoDcha && std::abs(adornosIzq - adornosDcha) <= 1;
		}

	}
};



#endif // bintree_eda_h

using namespace std;

// lee un árbol binario de la entrada estándar
bintree<char> leerArbol(char primero)
{
	if (primero == 'Y')
	{
		char dcha, izq;

		cin >> izq;  bintree<char> aux2 = leerArbol(izq);
		cin >> dcha; bintree<char> aux = leerArbol(dcha);


		return{ aux2, '.', aux };
	}
	else
	{
		return{ primero };
	}
}

int main()
{
	char c;
	cin >> c;

	while (cin)
	{
		int aux;
		bintree<char> arbol = leerArbol(c);

		if (arbol.bienDecorado(aux))
			cout << "OK\n";

		else
			cout << "KO\n";

		cin >> c;
	}

	return 0;
}
