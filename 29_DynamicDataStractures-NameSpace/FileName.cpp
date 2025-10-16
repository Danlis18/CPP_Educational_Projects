#include <iostream>
using namespace std;

namespace dynamicDataStractures {

	namespace lists {
		namespace singleLinkedList {

			int get_random_number(int min, int max) {
				return rand() % (max - min + 1) + min;
			}

			struct element {
				int data = 0;
				element* next = nullptr;
			};

			class list {
				element* head, * tail;
				int size;

			public:
				list() {
					head = tail = nullptr;
					size = 0;
				}

				void add_head(int value) {

					element* new_element = new element;
					new_element->data = value;

					if (size == 0) {
						head = tail = new_element;
					}
					else {
						new_element->next = head;
						head = new_element;
						new_element = nullptr;
					}

					size++;

				}

				void add_tail(int value) {
					element* new_element = new element;
					new_element->data = value;

					if (size == 0) {
						head = tail = new_element;
					}
					else {
						tail->next = new_element;
						tail = new_element;
						new_element = nullptr;
					}

					size++;
				}


				void delete_head() {
					element* tmp = head;

					if (size == 0) {
						return;
					}
					else {
						head = head->next;
						delete tmp;
						tmp = nullptr;
					}
					size--;
				}

				void delete_tail() {
					element* tmp = head;

					if (size == 0) {
						return;
					}

					else if (size == 1) {
						delete head;
						head = nullptr;
					}

					else {
						while (tmp->next != tail) {
							tmp = tmp->next;
						}
						delete tail;
						tail = tmp;
						tmp->next = nullptr;
						tmp = nullptr;
					}
					size--;
				}

				void clear() {
					while (size != 0) {
						delete_head();
					}
				}

				void add_pos(int pos, int value) {

					if (size == 0) add_head(value);
					else if (pos == size) add_tail(value);
					else {
						element* new_element = new element;
						new_element->data = value;

						element* tmp = head;

						int i = 0;
						while (i++ < pos - 1)
							tmp = tmp->next;

						new_element->next = tmp->next;

						tmp->next = new_element;

						size++;
					}
				}

				void dell_pos(int pos) {
					if (size == 0) return;

					if (pos == 0) {
						element* tmp = head;
						head = head->next;
						delete tmp;
					}
					else {
						element* tmp = head;
						int i = 0;
						while (i++ < pos - 1 && tmp->next != nullptr)
							tmp = tmp->next;

						if (tmp->next != nullptr) {
							element* to_delete = tmp->next;
							tmp->next = tmp->next->next;
							delete to_delete;
						}
						else {
							return;
						}
					}

					size--;
				}


				void print() const {

					element* tmp = head;

					while (tmp) {
						cout << tmp->data << " ";
						tmp = tmp->next;
					}
				}

				void set(int size) {
					for (int i = 0; i < size; i++)
						add_head(get_random_number(-50, 50));
				}


				~list() {
					clear();
				}
			};
		}

		namespace doublelinkedList {


			int get_random_number(int min, int max) {
				return rand() % (max - min + 1) + min;
			}

			struct element {
				int data = 0;
				element* next = nullptr;
				element* prev = nullptr;
			};

			class list {
				element* head, * tail;
				int size;

			public:
				list() {
					head = tail = nullptr;
					size = 0;
				}

				~list() {
					clear();
				}

				void add_head(int value) {
					element* new_element = new element;
					new_element->data = value;

					if (size == 0) {
						head = tail = new_element;
					}
					else {
						new_element->next = head;
						head->prev = new_element;
						head = new_element;
					}
					size++;
				}

				void add_tail(int value) {
					element* new_element = new element;
					new_element->data = value;

					if (size == 0) {
						head = tail = new_element;
					}
					else {
						tail->next = new_element;
						new_element->prev = tail;
						tail = new_element;
					}
					size++;
				}

				void delete_head() {
					if (size == 0) return;

					element* tmp = head;
					head = head->next;
					if (head) head->prev = nullptr;
					else tail = nullptr; // якщо був лише один елемент
					delete tmp;
					size--;
				}

				void delete_tail() {
					if (size == 0) return;

					element* tmp = tail;
					tail = tail->prev;
					if (tail) tail->next = nullptr;
					else head = nullptr; // якщо був лише один елемент
					delete tmp;
					size--;
				}

				void clear() {
					while (size > 0) {
						delete_head();
					}
				}

				void add_pos(int value, int pos) {
					if (pos <= 0) add_head(value);
					else if (pos >= size) add_tail(value);
					else {
						element* new_element = new element;
						new_element->data = value;

						element* tmp = head;
						for (int i = 0; i < pos - 1; i++)
							tmp = tmp->next;

						new_element->next = tmp->next;
						new_element->prev = tmp;
						tmp->next->prev = new_element;
						tmp->next = new_element;

						size++;
					}
				}

				void delete_pos(int pos) {
					if (size == 0) return;
					if (pos <= 0) {
						delete_head();
					}
					else if (pos >= size - 1) {
						delete_tail();
					}
					else {
						element* tmp = head;
						for (int i = 0; i < pos; i++)
							tmp = tmp->next;

						tmp->prev->next = tmp->next;
						tmp->next->prev = tmp->prev;
						delete tmp;
						size--;
					}
				}

				void print() const {
					element* tmp = head;
					while (tmp) {
						cout << tmp->data << " ";
						tmp = tmp->next;
					}
					cout << endl;
				}

				void set(int s) {
					for (int i = 0; i < s; i++)
						add_head(get_random_number(-50, 50));
				}
			};
		}
	}

	namespace stack {
		void line(int count) {
			cout << "\n";
			for (int i = 0; i < count; i++)
				cout << "-";
			cout << "\n";
		}

		class vector {
		private:
			int* data;
			int size;

		public:
			vector() {
				data = nullptr;
				size = 0;
			}

			vector(int size) { // 10
				// this->data = new int[size];
				for (int i = 0; i < size; i++)
					add_element_end(rand() % 101 - 50);
			}

			vector(const vector& other) {
				this->data = new int[other.size];
				this->size = other.size;

				for (int i = 0; i < other.size; i++)
				{
					this->data[i] = other.data[i];
					// *(this->data + i) = *(other.data + i);
				}
			}

			void print_v() const {
				line(100);
				for (int i = 0; i < size; i++)
					cout << *(data + i) << " ";
				line(100);
			}

			void set_random(int size) {
				for (int i = 0; i < size; i++) {
					add_element_end(rand() % 101 - 50);
				}
			}

			void add_element_start(int number) {
				int* p = new int[size + 1];

				for (int i = 1; i < size + 1; i++)
					*(p + i) = *(data + i - 1);

				p[0] = number;

				delete[] data;
				data = p;
				size++;
				p = nullptr;
			}

			void add_element_end(int number) {
				int* p = new int[size + 1];

				for (int i = 0; i < size; i++)
					*(p + i) = *(data + i);

				p[size] = number;
				delete[] data;
				data = p;
				size++;
				p = nullptr;
			}

			void add_element_need(int wher, int number) {
				int* p = new int[size + 1];

				for (int i = 0; i < wher; i++) {
					p[i] = data[i];
				}

				p[wher] = number;

				for (int i = wher; i < size; i++) {
					p[i + 1] = data[i];
				}

				delete[] data;
				data = p;
				size++;
				p = nullptr;
			}

			void deletee_element_last() {
				size--;
				int* p = new int[size];

				for (int i = 0; i < size; i++) {
					p[i] = data[i];
				}

				delete[] data;
				data = p;
				p = nullptr;
			}

			void deletee_element_first() {
				size--;
				int* p = new int[size];

				for (int i = 0; i < size; i++) {
					p[i] = data[i + 1];
				}

				delete[] data;
				data = p;
				p = nullptr;
			}

			void delete_element_position(int position) {
				int* p = new int[size - 1];

				for (int i = 0, j = 0; i < size; i++) {
					if (i != position) {
						p[j++] = data[i];
					}
				}

				delete[] data;
				data = p;
				size--;
				p = nullptr;
			}

			int search_element_position(int element) {
				for (int i = 0; i < size; i++)
					if (data[i] == element)
						return i;
				return -1;
			}

			void delete_search_element(int element) {
				int position = search_element_position(element);
				if (position != -1)
					delete_element_position(position);
				else {
					cout << "Element not found";
				}
			}

			void delete_elements_from_position(int count, int position) {
				for (int i = 0; i < count; i++)
					delete_element_position(position);
			}

			void delete_array() {
				delete[] data;
				data = nullptr;
				size = 0;
			}

			void change_element_by_value(int number, int change_number) {
				int position = search_element_position(number);
				if (position != -1)
					data[position] = change_number;
				else {
					cout << "Not found";

				}
			}

			void change_element_by_position(int position, int change_number) {
				data[position] = change_number;
			}



			void reverse_array() {
				for (int i = 0; i < size / 2; i++) {
					swap(data[i], data[size - i - 1]);
				}
			}

			int get_max() {
				if (size == 0) {
					cout << "Array is empty\n";

					return 0;
				}
				int max_val = data[0];
				for (int i = 1; i < size; i++)
					if (data[i] > max_val)
						max_val = data[i];
				return max_val;
			}

			int get_min() {
				if (size == 0) {
					cout << "Array is empty\n";

					return 0;
				}
				int min_val = data[0];
				for (int i = 1; i < size; i++)
					if (data[i] < min_val)
						min_val = data[i];
				return min_val;
			}

			int get_size() const {
				return size;
			}

			int get_element(int index) {
				if (index < 0 || index >= size) {
					cout << "Incorrect index!\n";

					return 0;
				}
				return data[index];
			}

			void sort_asc() {
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - i - 1; j++) {
						if (data[j] > data[j + 1])
							swap(data[j], data[j + 1]);
					}
				}
			}

			void sort_desc() {
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - i - 1; j++) {
						if (data[j] < data[j + 1])
							swap(data[j], data[j + 1]);
					}
				}
			}

			void print() {
				line(100);
				for (int i = 0; i < size; i++)
					cout << *(data + i) << " ";
				line(100);
			}

			void print_info_max() {
				cout << "\n======= ARRAY INFO =======\n";

				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "Max element: " << get_max() << endl;

			}

			void print_info_min() {
				cout << "\n======= ARRAY INFO =======\n";

				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "Min element: " << get_min() << endl;

			}

			void print_info_size() {
				cout << "\n======= ARRAY INFO =======\n";

				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "Size: " << size << endl;

			}

			void print_info_index() {
				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "\n======= ARRAY INFO =======\n";
				int index;
				cout << "Enter index: ";
				cin >> index;

				int value = get_element(index);
				cout << "Element at index " << index << " is: " << value << endl;

			}




			vector operator=(const vector& other) {
				if (this == &other)
					return *this;

				if (this->data) {
					delete[] this->data;
				}
				this->data = new int[other.size];

				for (int i = 0; i < other.size; i++)
				{
					this->data[i] = other.data[i];
				}
				this->size = other.size;

				return *this;
			}

			int& get_element_by_index(unsigned int index) {
				if (index >= size)
					throw exception("index out of range");

				return data[index];
			}

			int& operator[](unsigned int index) {
				if (index >= size)
					throw exception("index out of range");

				return data[index];
			}



			bool is_empty() const {
				return size == 0;
			}


			~vector() {
				delete[] data;
			}
		};

		ostream& operator<< (ostream& os, const vector& obj) {
			obj.print_v();
			return os;
		}

		istream& operator>> (istream& is, vector& obj) {
			obj.set_random(10);
			return is;
		}

		class stack {
			vector data;
		public:

			void push(int value) {
				data.add_element_start(value);
			}



			void print() const {
				data.print_v();
			}

			int top() {
				if (!is_empty())
					return data[0];

				throw exception("Stack is empty");
			}


			bool is_empty() const {
				return data.is_empty();
			}

			int pop() {
				if (!is_empty()) {
					int tmp = data[0];
					data.deletee_element_first();
					return tmp;
				}
				throw exception("Stack is empty");
			}

			void clear() {
				data.delete_array();
			}


		};
	}

	namespace queues {
		namespace queue {
			void line(int count) {
				cout << "\n";
				for (int i = 0; i < count; i++)
					cout << "-";
				cout << "\n";
			}

			class vector {
			private:
				int* data;
				int size;

			public:
				vector() {
					data = nullptr;
					size = 0;
				}

				vector(int size) { // 10
					// this->data = new int[size];
					for (int i = 0; i < size; i++)
						add_element_end(rand() % 101 - 50);
				}

				vector(const vector& other) {
					this->data = new int[other.size];
					this->size = other.size;

					for (int i = 0; i < other.size; i++)
					{
						this->data[i] = other.data[i];
						// *(this->data + i) = *(other.data + i);
					}
				}

				void print_v() const {
					line(100);
					for (int i = 0; i < size; i++)
						cout << *(data + i) << " ";
					line(100);
				}

				void set_random(int size) {
					for (int i = 0; i < size; i++) {
						add_element_end(rand() % 101 - 50);
					}
				}

				void add_element_start(int number) {
					int* p = new int[size + 1];

					for (int i = 1; i < size + 1; i++)
						*(p + i) = *(data + i - 1);

					p[0] = number;

					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void add_element_end(int number) {
					int* p = new int[size + 1];

					for (int i = 0; i < size; i++)
						*(p + i) = *(data + i);

					p[size] = number;
					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void add_element_need(int wher, int number) {
					int* p = new int[size + 1];

					for (int i = 0; i < wher; i++) {
						p[i] = data[i];
					}

					p[wher] = number;

					for (int i = wher; i < size; i++) {
						p[i + 1] = data[i];
					}

					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void deletee_element_last() {
					size--;
					int* p = new int[size];

					for (int i = 0; i < size; i++) {
						p[i] = data[i];
					}

					delete[] data;
					data = p;
					p = nullptr;
				}

				void deletee_element_first() {
					size--;
					int* p = new int[size];

					for (int i = 0; i < size; i++) {
						p[i] = data[i + 1];
					}

					delete[] data;
					data = p;
					p = nullptr;
				}

				void delete_element_position(int position) {
					int* p = new int[size - 1];

					for (int i = 0, j = 0; i < size; i++) {
						if (i != position) {
							p[j++] = data[i];
						}
					}

					delete[] data;
					data = p;
					size--;
					p = nullptr;
				}

				int search_element_position(int element) {
					for (int i = 0; i < size; i++)
						if (data[i] == element)
							return i;
					return -1;
				}

				void delete_search_element(int element) {
					int position = search_element_position(element);
					if (position != -1)
						delete_element_position(position);
					else {
						cout << "Element not found";
					}
				}

				void delete_elements_from_position(int count, int position) {
					for (int i = 0; i < count; i++)
						delete_element_position(position);
				}

				void delete_array() {
					delete[] data;
					data = nullptr;
					size = 0;
				}

				void change_element_by_value(int number, int change_number) {
					int position = search_element_position(number);
					if (position != -1)
						data[position] = change_number;
					else {
						cout << "Not found";

					}
				}

				void change_element_by_position(int position, int change_number) {
					data[position] = change_number;
				}

				void reverse_array() {
					for (int i = 0; i < size / 2; i++) {
						swap(data[i], data[size - i - 1]);
					}
				}

				int get_max() {
					if (size == 0) {
						cout << "Array is empty\n";

						return 0;
					}
					int max_val = data[0];
					for (int i = 1; i < size; i++)
						if (data[i] > max_val)
							max_val = data[i];
					return max_val;
				}

				int get_min() {
					if (size == 0) {
						cout << "Array is empty\n";

						return 0;
					}
					int min_val = data[0];
					for (int i = 1; i < size; i++)
						if (data[i] < min_val)
							min_val = data[i];
					return min_val;
				}

				int get_size() const {
					return size;
				}

				int get_element(int index) {
					if (index < 0 || index >= size) {
						cout << "Incorrect index!\n";

						return 0;
					}
					return data[index];
				}

				void sort_asc() {
					for (int i = 0; i < size - 1; i++) {
						for (int j = 0; j < size - i - 1; j++) {
							if (data[j] > data[j + 1])
								swap(data[j], data[j + 1]);
						}
					}
				}

				void sort_desc() {
					for (int i = 0; i < size - 1; i++) {
						for (int j = 0; j < size - i - 1; j++) {
							if (data[j] < data[j + 1])
								swap(data[j], data[j + 1]);
						}
					}
				}

				void print() {
					line(100);
					for (int i = 0; i < size; i++)
						cout << *(data + i) << " ";
					line(100);
				}

				void print_info_max() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Max element: " << get_max() << endl;

				}

				void print_info_min() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Min element: " << get_min() << endl;

				}

				void print_info_size() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Size: " << size << endl;

				}

				void print_info_index() {
					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "\n======= ARRAY INFO =======\n";
					int index;
					cout << "Enter index: ";
					cin >> index;

					int value = get_element(index);
					cout << "Element at index " << index << " is: " << value << endl;

				}




				vector operator=(const vector& other) {
					if (this == &other)
						return *this;

					if (this->data) {
						delete[] this->data;
					}
					this->data = new int[other.size];

					for (int i = 0; i < other.size; i++)
					{
						this->data[i] = other.data[i];
					}
					this->size = other.size;

					return *this;
				}

				int& get_element_by_index(unsigned int index) {
					if (index >= size)
						throw exception("index out of range");

					return data[index];
				}

				int& operator[](unsigned int index) {
					if (index >= size)
						throw exception("index out of range");

					return data[index];
				}



				bool is_empty() const {
					return size == 0;
				}


				~vector() {
					delete[] data;
				}
			};

			ostream& operator<< (ostream& os, const vector& obj) {
				obj.print_v();
				return os;
			}

			istream& operator>> (istream& is, vector& obj) {
				obj.set_random(10);
				return is;
			}

			class queue {
				vector data;
			public:

				void push(int value) {
					data.add_element_end(value);
				}

				void print() const {
					data.print_v();
				}

				int top() {
					if (!is_empty())
						return data[0];

					throw exception("Queue is empty");
				}


				bool is_empty() const {
					return data.is_empty();
				}

				int pop() {
					if (!is_empty()) {
						int tmp = data[0];
						data.deletee_element_first();
						return tmp;
					}
					throw exception("Queue is empty");
				}

				void clear() {
					data.delete_array();
				}


			};
		}

		namespace RingQueue {
			void line(int count) {
				cout << "\n";
				for (int i = 0; i < count; i++)
					cout << "-";
				cout << "\n";
			}

			class vector {
			private:
				int* data;
				int size;

			public:
				vector() {
					data = nullptr;
					size = 0;
				}

				vector(int size) { // 10
					// this->data = new int[size];
					for (int i = 0; i < size; i++)
						add_element_end(rand() % 101 - 50);
				}

				vector(const vector& other) {
					this->data = new int[other.size];
					this->size = other.size;

					for (int i = 0; i < other.size; i++)
					{
						this->data[i] = other.data[i];
						// *(this->data + i) = *(other.data + i);
					}
				}

				void print_v() const {
					line(100);
					for (int i = 0; i < size; i++)
						cout << *(data + i) << " ";
					line(100);
				}

				void set_random(int size) {
					for (int i = 0; i < size; i++) {
						add_element_end(rand() % 101 - 50);
					}
				}

				void add_element_start(int number) {
					int* p = new int[size + 1];

					for (int i = 1; i < size + 1; i++)
						*(p + i) = *(data + i - 1);

					p[0] = number;

					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void add_element_end(int number) {
					int* p = new int[size + 1];

					for (int i = 0; i < size; i++)
						*(p + i) = *(data + i);

					p[size] = number;
					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void add_element_need(int wher, int number) {
					int* p = new int[size + 1];

					for (int i = 0; i < wher; i++) {
						p[i] = data[i];
					}

					p[wher] = number;

					for (int i = wher; i < size; i++) {
						p[i + 1] = data[i];
					}

					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void deletee_element_last() {
					size--;
					int* p = new int[size];

					for (int i = 0; i < size; i++) {
						p[i] = data[i];
					}

					delete[] data;
					data = p;
					p = nullptr;
				}

				void deletee_element_first() {
					size--;
					int* p = new int[size];

					for (int i = 0; i < size; i++) {
						p[i] = data[i + 1];
					}

					delete[] data;
					data = p;
					p = nullptr;
				}

				void delete_element_position(int position) {
					int* p = new int[size - 1];

					for (int i = 0, j = 0; i < size; i++) {
						if (i != position) {
							p[j++] = data[i];
						}
					}

					delete[] data;
					data = p;
					size--;
					p = nullptr;
				}

				int search_element_position(int element) {
					for (int i = 0; i < size; i++)
						if (data[i] == element)
							return i;
					return -1;
				}

				void delete_search_element(int element) {
					int position = search_element_position(element);
					if (position != -1)
						delete_element_position(position);
					else {
						cout << "Element not found";
					}
				}

				void delete_elements_from_position(int count, int position) {
					for (int i = 0; i < count; i++)
						delete_element_position(position);
				}

				void delete_array() {
					delete[] data;
					data = nullptr;
					size = 0;
				}

				void change_element_by_value(int number, int change_number) {
					int position = search_element_position(number);
					if (position != -1)
						data[position] = change_number;
					else {
						cout << "Not found";

					}
				}

				void change_element_by_position(int position, int change_number) {
					data[position] = change_number;
				}

				void reverse_array() {
					for (int i = 0; i < size / 2; i++) {
						swap(data[i], data[size - i - 1]);
					}
				}

				int get_max() {
					if (size == 0) {
						cout << "Array is empty\n";

						return 0;
					}
					int max_val = data[0];
					for (int i = 1; i < size; i++)
						if (data[i] > max_val)
							max_val = data[i];
					return max_val;
				}

				int get_min() {
					if (size == 0) {
						cout << "Array is empty\n";

						return 0;
					}
					int min_val = data[0];
					for (int i = 1; i < size; i++)
						if (data[i] < min_val)
							min_val = data[i];
					return min_val;
				}

				int get_size() const {
					return size;
				}

				int get_element(int index) {
					if (index < 0 || index >= size) {
						cout << "Incorrect index!\n";

						return 0;
					}
					return data[index];
				}

				void sort_asc() {
					for (int i = 0; i < size - 1; i++) {
						for (int j = 0; j < size - i - 1; j++) {
							if (data[j] > data[j + 1])
								swap(data[j], data[j + 1]);
						}
					}
				}

				void sort_desc() {
					for (int i = 0; i < size - 1; i++) {
						for (int j = 0; j < size - i - 1; j++) {
							if (data[j] < data[j + 1])
								swap(data[j], data[j + 1]);
						}
					}
				}

				void print() {
					line(100);
					for (int i = 0; i < size; i++)
						cout << *(data + i) << " ";
					line(100);
				}

				void print_info_max() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Max element: " << get_max() << endl;

				}

				void print_info_min() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Min element: " << get_min() << endl;

				}

				void print_info_size() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Size: " << size << endl;

				}

				void print_info_index() {
					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "\n======= ARRAY INFO =======\n";
					int index;
					cout << "Enter index: ";
					cin >> index;

					int value = get_element(index);
					cout << "Element at index " << index << " is: " << value << endl;

				}




				vector operator=(const vector& other) {
					if (this == &other)
						return *this;

					if (this->data) {
						delete[] this->data;
					}
					this->data = new int[other.size];

					for (int i = 0; i < other.size; i++)
					{
						this->data[i] = other.data[i];
					}
					this->size = other.size;

					return *this;
				}

				int& get_element_by_index(unsigned int index) {
					if (index >= size)
						throw exception("index out of range");

					return data[index];
				}

				int& operator[](unsigned int index) {
					if (index >= size)
						throw exception("index out of range");

					return data[index];
				}



				bool is_empty() const {
					return size == 0;
				}


				~vector() {
					delete[] data;
				}
			};

			ostream& operator<< (ostream& os, const vector& obj) {
				obj.print_v();
				return os;
			}

			istream& operator>> (istream& is, vector& obj) {
				obj.set_random(10);
				return is;
			}

			class ringQueue {
				vector data;
			public:
				int set_random() {
					int randValue = rand() % 100 + 1;
					return randValue;
				}

				void push(int value) {
					data.add_element_end(value);
				}

				void print() const {
					data.print_v();
				}

				int top() {
					if (!is_empty())
						return data[0];

					throw exception("Queue is empty");
				}


				bool is_empty() const {
					return data.is_empty();
				}

				int pop() {
					if (!is_empty()) {
						int tmp = data[0];
						data.deletee_element_first();
						data.add_element_end(tmp);
						return tmp;
					}
					throw exception("Queue is empty");
				}

				int randSpin() {
					for (int i = 0; i < set_random(); i++)
					{
						pop();
					}
					return top();
				}

				void clear() {
					data.delete_array();
				}
			};
		}

		namespace PriorityQueue {
			void line(int count) {
				cout << "\n";
				for (int i = 0; i < count; i++)
					cout << "-";
				cout << "\n";
			}

			class priority_item {
				int data;
				int priority;

			public:
				priority_item() {
					data = 0;
					priority = 0;
				}

				priority_item(int data, int priority) {
					this->data = data;
					this->priority = priority;
				}

				void print() const {
					cout << "Data: " << data << " | Priority: " << priority << "\n";
				}
				int get_priority() const {
					return priority;
				}
			};

			ostream& operator<< (ostream& os, const priority_item& obj) {
				obj.print();
				return os;
			}

			class vector {
			private:
				priority_item* data;
				int size;

			public:
				vector() {
					data = nullptr;
					size = 0;
				}



				vector(const vector& other) {
					this->data = new priority_item[other.size];
					this->size = other.size;

					for (int i = 0; i < other.size; i++)
					{
						this->data[i] = other.data[i];
						// *(this->data + i) = *(other.data + i);
					}
				}

				void print_v() const {
					line(100);
					for (int i = 0; i < size; i++)
						cout << *(data + i) << " ";
					line(100);
				}


				void add_element_start(priority_item number) {
					priority_item* p = new priority_item[size + 1];

					for (int i = 1; i < size + 1; i++)
						*(p + i) = *(data + i - 1);

					p[0] = number;

					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void add_element_end(priority_item number) {
					priority_item* p = new priority_item[size + 1];

					for (int i = 0; i < size; i++)
						*(p + i) = *(data + i);

					p[size] = number;
					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void add_element_need(int wher, priority_item number) {
					priority_item* p = new priority_item[size + 1];

					for (int i = 0; i < wher; i++) {
						p[i] = data[i];
					}

					p[wher] = number;

					for (int i = wher; i < size; i++) {
						p[i + 1] = data[i];
					}

					delete[] data;
					data = p;
					size++;
					p = nullptr;
				}

				void deletee_element_last() {
					size--;
					priority_item* p = new priority_item[size];

					for (int i = 0; i < size; i++) {
						p[i] = data[i];
					}

					delete[] data;
					data = p;
					p = nullptr;
				}

				void deletee_element_first() {
					size--;
					priority_item* p = new priority_item[size];

					for (int i = 0; i < size; i++) {
						p[i] = data[i + 1];
					}

					delete[] data;
					data = p;
					p = nullptr;
				}

				void delete_element_position(int position) {
					priority_item* p = new priority_item[size - 1];

					for (int i = 0, j = 0; i < size; i++) {
						if (i != position) {
							p[j++] = data[i];
						}
					}

					delete[] data;
					data = p;
					size--;
					p = nullptr;
				}





				void delete_elements_from_position(int count, int position) {
					for (int i = 0; i < count; i++)
						delete_element_position(position);
				}

				void delete_array() {
					delete[] data;
					data = nullptr;
					size = 0;
				}




				int get_size() const {
					return size;
				}


				void print() {
					line(100);
					for (int i = 0; i < size; i++)
						cout << *(data + i) << " ";
					line(100);
				}


				void print_info_size() {
					cout << "\n======= ARRAY INFO =======\n";

					if (size == 0) {
						cout << "Array is empty!\n";
						return;
					}
					cout << "Size: " << size << endl;

				}


				vector operator=(const vector& other) {
					if (this == &other)
						return *this;

					if (this->data) {
						delete[] this->data;
					}
					this->data = new priority_item[other.size];

					for (int i = 0; i < other.size; i++)
					{
						this->data[i] = other.data[i];
					}
					this->size = other.size;

					return *this;
				}

				priority_item& get_element_by_index(unsigned int index) {
					if (index >= size)
						throw exception("index out of range");

					return data[index];
				}

				priority_item& operator[](unsigned int index) {
					if (index >= size)
						throw exception("index out of range");

					return data[index];
				}



				bool is_empty() const {
					return size == 0;
				}


				~vector() {
					delete[] data;
				}
			};

			ostream& operator<< (ostream& os, const vector& obj) {
				obj.print_v();
				return os;
			}

			class queue {
				vector data;
			public:

				void push(priority_item value) {

					if (is_empty())
						data.add_element_start(value);
					else {
						int i = 0;
						while (i < data.get_size() &&
							data[i].get_priority() <= value.get_priority()) {
							i++;
						}
						data.add_element_need(i, value);
					}


				}

				void print() const {
					data.print_v();
				}

				priority_item top() {
					if (!is_empty())
						return data[0];

					throw exception("Queue is empty");
				}


				bool is_empty() const {
					return data.is_empty();
				}

				priority_item pop() {
					if (!is_empty()) {
						priority_item tmp = data[0];
						data.deletee_element_first();
						return tmp;
					}
					throw exception("Queue is empty");
				}

				void clear() {
					data.delete_array();
				}
			};
		}
	}

	namespace binaryTree {
		struct element {
			int key;
			element* left, * right, * perent;

			element() {
				key = 0;
				left = right = perent = nullptr;
			}
		};

		class tree {
			element* root;
			int count;

		public:
			tree() {
				root = nullptr;
				count = 0;
			}

			void insert(int key) {
				element* node = new element;
				node->key = key;
				element* ptr = nullptr, * tmp = root;

				while (tmp) { //шукали батьківський елемент цим циклом.
					ptr = tmp;
					if (node->key < tmp->key)
						tmp = tmp->right;
					else
						tmp = tmp->right;
				}

				if (ptr == nullptr) {
					root = node;
				}
				else if (node->key < ptr->key)
					ptr->left = node;
				else
					ptr->right = node;

				count++;
			}

			element* minimum(element* node) const {

				if (node) {
					while (node->left) {
						node = node->left;
					}
				}
				return node;
			}

			element* maximum(element* node) const {
				if (node) {
					while (node->right) {
						node = node->right;
					}
				}

				return node;
			}


			element* search(element* node, int key) {
				while (node && node->key != key) {
					if (key < node->key)
						node = node->left;
					else
						node = node->right;
				}
				return node;
			}


			void print(element* node) const {
				if (node) { //if(node != nullptr)
					print(node->left);
					cout << node->key << " ";
					print(node->right);
				}
			}

			element* get_root() const {
				return root;
			}
		};
	}

	namespace vector {
		void line(int count) {
			cout << "\n";
			for (int i = 0; i < count; i++)
				cout << "-";
			cout << "\n";
		}

		class vector {
		private:
			int* data;
			int size;

		public:
			vector() {
				data = nullptr;
				size = 0;
			}

			vector(int size) { // 10
				// this->data = new int[size];
				for (int i = 0; i < size; i++)
					add_element_end(rand() % 101 - 50);
			}

			vector(const vector& other) {
				this->data = new int[other.size];
				this->size = other.size;

				for (int i = 0; i < other.size; i++)
				{
					this->data[i] = other.data[i];
					// *(this->data + i) = *(other.data + i);
				}
			}

			void print_v() const {
				line(100);
				for (int i = 0; i < size; i++)
					cout << *(data + i) << " ";
				line(100);
			}

			void set_random(int size) {
				for (int i = 0; i < size; i++) {
					add_element_end(rand() % 101 - 50);
				}
			}

			void add_element_start(int number) {
				int* p = new int[size + 1];

				for (int i = 1; i < size + 1; i++)
					*(p + i) = *(data + i - 1);

				p[0] = number;

				delete[] data;
				data = p;
				size++;
				p = nullptr;
			}

			void add_element_end(int number) {
				int* p = new int[size + 1];

				for (int i = 0; i < size; i++)
					*(p + i) = *(data + i);

				p[size] = number;
				delete[] data;
				data = p;
				size++;
				p = nullptr;
			}

			void add_element_need(int wher, int number) {
				int* p = new int[size + 1];

				for (int i = 0; i < wher; i++) {
					p[i] = data[i];
				}

				p[wher] = number;

				for (int i = wher; i < size; i++) {
					p[i + 1] = data[i];
				}

				delete[] data;
				data = p;
				size++;
				p = nullptr;
			}

			void deletee_element_last() {
				size--;
				int* p = new int[size];

				for (int i = 0; i < size; i++) {
					p[i] = data[i];
				}

				delete[] data;
				data = p;
				p = nullptr;
			}

			void deletee_element_first() {
				size--;
				int* p = new int[size];

				for (int i = 0; i < size; i++) {
					p[i] = data[i + 1];
				}

				delete[] data;
				data = p;
				p = nullptr;
			}

			void delete_element_position(int position) {
				int* p = new int[size - 1];

				for (int i = 0, j = 0; i < size; i++) {
					if (i != position) {
						p[j++] = data[i];
					}
				}

				delete[] data;
				data = p;
				size--;
				p = nullptr;
			}

			int search_element_position(int element) {
				for (int i = 0; i < size; i++)
					if (data[i] == element)
						return i;
				return -1;
			}

			void delete_search_element(int element) {
				int position = search_element_position(element);
				if (position != -1)
					delete_element_position(position);
				else {
					cout << "Element not found";
				}
			}

			void delete_elements_from_position(int count, int position) {
				for (int i = 0; i < count; i++)
					delete_element_position(position);
			}

			void delete_array() {
				delete[] data;
				data = nullptr;
				size = 0;
			}

			void change_element_by_value(int number, int change_number) {
				int position = search_element_position(number);
				if (position != -1)
					data[position] = change_number;
				else {
					cout << "Not found";

				}
			}

			void change_element_by_position(int position, int change_number) {
				data[position] = change_number;
			}



			void reverse_array() {
				for (int i = 0; i < size / 2; i++) {
					swap(data[i], data[size - i - 1]);
				}
			}

			int get_max() {
				if (size == 0) {
					cout << "Array is empty\n";

					return 0;
				}
				int max_val = data[0];
				for (int i = 1; i < size; i++)
					if (data[i] > max_val)
						max_val = data[i];
				return max_val;
			}

			int get_min() {
				if (size == 0) {
					cout << "Array is empty\n";

					return 0;
				}
				int min_val = data[0];
				for (int i = 1; i < size; i++)
					if (data[i] < min_val)
						min_val = data[i];
				return min_val;
			}

			int get_size() const {
				return size;
			}

			int get_element(int index) {
				if (index < 0 || index >= size) {
					cout << "Incorrect index!\n";

					return 0;
				}
				return data[index];
			}

			void sort_asc() {
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - i - 1; j++) {
						if (data[j] > data[j + 1])
							swap(data[j], data[j + 1]);
					}
				}
			}

			void sort_desc() {
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - i - 1; j++) {
						if (data[j] < data[j + 1])
							swap(data[j], data[j + 1]);
					}
				}
			}

			void print() {
				line(100);
				for (int i = 0; i < size; i++)
					cout << *(data + i) << " ";
				line(100);
			}

			void print_info_max() {
				cout << "\n======= ARRAY INFO =======\n";

				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "Max element: " << get_max() << endl;

			}

			void print_info_min() {
				cout << "\n======= ARRAY INFO =======\n";

				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "Min element: " << get_min() << endl;

			}

			void print_info_size() {
				cout << "\n======= ARRAY INFO =======\n";

				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "Size: " << size << endl;

			}

			void print_info_index() {
				if (size == 0) {
					cout << "Array is empty!\n";
					return;
				}
				cout << "\n======= ARRAY INFO =======\n";
				int index;
				cout << "Enter index: ";
				cin >> index;

				int value = get_element(index);
				cout << "Element at index " << index << " is: " << value << endl;

			}




			vector operator=(const vector& other) {
				if (this == &other)
					return *this;

				if (this->data) {
					delete[] this->data;
				}
				this->data = new int[other.size];

				for (int i = 0; i < other.size; i++)
				{
					this->data[i] = other.data[i];
				}
				this->size = other.size;

				return *this;
			}

			int& get_element_by_index(unsigned int index) {
				if (index >= size)
					throw exception("index out of range");

				return data[index];
			}

			int& operator[](unsigned int index) {
				if (index >= size)
					throw exception("index out of range");

				return data[index];
			}



			bool is_empty() const {
				return size == 0;
			}


			~vector() {
				delete[] data;
			}
		};

		ostream& operator<< (ostream& os, const vector& obj) {
			obj.print_v();
			return os;
		}

		istream& operator>> (istream& is, vector& obj) {
			obj.set_random(10);
			return is;
		}
	}
}




int main() {
	dynamicDataStractures::lists::singleLinkedList::list l1;
	dynamicDataStractures::lists::doublelinkedList::list l2;

	dynamicDataStractures::queues::queue::queue q1;
	dynamicDataStractures::queues::RingQueue::ringQueue q2;
	dynamicDataStractures::queues::PriorityQueue::queue q3;

	dynamicDataStractures::stack::stack s;
 
	dynamicDataStractures::binaryTree::tree Tree;

	dynamicDataStractures::vector::vector v;




	return 0;
}