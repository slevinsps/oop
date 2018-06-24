#pragma once
#include <memory>
namespace myList {
	template<typename T>
	class Node {
	private:
		T data;
		std::shared_ptr<Node<T>> next;
	public:
		Node() : next(nullptr) {}
		Node(const T &elem) : data(elem), next(nullptr) {}

		~Node() {
			next = nullptr;
		}

		T& get_object() const {
			return const_cast<T&>(data);
		}

		std::shared_ptr<Node<T>> get_next() const {
			return next;
		}

		void set_next(std::shared_ptr<Node<T>> next) {
			Node::next = next;
		}
		void set_data(T data) {
			Node::data = data;
		}
		T& get_data() {
			return data;
		}
	};
}