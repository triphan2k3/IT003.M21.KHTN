#include "rbtree.h"

RBTree::RBTree() {
    this->root = NULL;
}

RBTree::~RBTree() {
    while (root != NULL)
        erase(root->data);   
}

Node* RBTree::begin() {
    return minNode();
}

Node* RBTree::rend() {
    return NULL;
}

Node* RBTree::rbegin() {
    return maxNode();
}

Node* RBTree::end() {
    return NULL;
}

Node* RBTree::Next(Node *ptr) {
    if (ptr == rbegin()) return NULL;

    if (ptr->rightChild != NULL)
        return minimumRight(ptr);

    while (ptr == ptr->parent->rightChild)
        ptr = ptr->parent;
    return ptr->parent;
}

Node* RBTree::Prev(Node *ptr) {
    if (ptr == begin()) return NULL;
    if (ptr -> leftChild != NULL)
        return maximumLeft(ptr);
    
    while (ptr == ptr->parent->leftChild)
        ptr = ptr->parent;
    return ptr->parent;
}

int RBTree::getColor(Node *&ptr) {
    if (ptr == NULL)
        return BLACK;
    return ptr->color;
}

void RBTree::setColor(Node *&ptr, int color) {
    if (ptr == NULL)
        return;
    ptr->color = color;
}

int RBTree::getCount(Node *&ptr) {
    if (ptr == NULL)
        return 0;
    return ptr->count;
}
void RBTree::setCount(Node *&ptr) {
    ptr->count = getCount(ptr->leftChild) + getCount(ptr->rightChild) + 1;
}

void RBTree::rotateLeft(Node *&ptr) {
    Node *rightChild = ptr->rightChild;

    ptr->rightChild = rightChild->leftChild;
    if (ptr->rightChild != NULL)
        ptr->rightChild->parent = ptr;

    if (ptr == this->root)
        this->root = rightChild;

    else if (ptr == ptr->parent->leftChild)
        ptr->parent->leftChild = rightChild;
    else
        ptr->parent->rightChild = rightChild;

    rightChild->parent = ptr->parent;
    rightChild->leftChild = ptr;
    ptr->parent = rightChild;
    setCount(ptr);
    setCount(rightChild);
}

void RBTree::rotateRight(Node *&ptr) {
    Node *leftChild = ptr->leftChild;

    ptr->leftChild = leftChild->rightChild;
    if (ptr->leftChild != NULL)
        ptr->leftChild->parent = ptr;

    if (ptr == this->root)
        this->root = leftChild;
    else if (ptr == ptr->parent->leftChild)
        ptr->parent->leftChild = leftChild;
    else
        ptr->parent->rightChild = leftChild;

    leftChild->parent = ptr->parent;
    leftChild->rightChild = ptr;
    ptr->parent = leftChild;
    setCount(ptr);
    setCount(leftChild);
}

void RBTree::updateCount(Node *ptr, int flag) {
    while (ptr->parent != NULL) {
        ptr = ptr->parent;
        ptr->count += flag;
    }
}

void RBTree::insert(int data) {
    Node *ptr = new Node(RED,data);
    if (root == NULL) {
        root = ptr;
        root->color = BLACK;
        return;
    }
    Node *linker = root;
    while (linker != NULL) {
        if (data < linker->data) { // go left
            if (linker -> leftChild == NULL) {
                linker->leftChild = ptr;
                break;
            } else
                linker = linker->leftChild;
        } else { // go right
            if (linker->rightChild == NULL) {
                linker->rightChild = ptr;
                break;
            } else
                linker = linker->rightChild;
        }
    }
    ptr->parent = linker;
    updateCount(ptr, 1);
    insertFix(ptr);
}

void RBTree::insertFix(Node *&ptr) {
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        Node *parent = ptr->parent;
        Node *grandparent = parent->parent;
        if (parent == grandparent->leftChild) {
            Node *uncle = grandparent->rightChild;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->rightChild) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                setColor(grandparent, RED);
                setColor(parent, BLACK);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->leftChild;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->leftChild) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;

                }
                rotateLeft(grandparent);
                setColor(grandparent, RED);
                setColor(parent, BLACK);
                ptr = parent;
            }
        }

    }
    setColor(root, BLACK);
}

Node* RBTree::findID(int pos) {
    Node* ptr = this->root;
    if (pos > this->root->count) return NULL;
    while (ptr != NULL) {
        if (ptr->leftChild->count + 1 == pos)
            return ptr;
        if (ptr->leftChild->count < pos) {
            pos -= ptr->leftChild->count;
            ptr = ptr->rightChild;
        } else
            ptr = ptr->leftChild;
    }
    return ptr;
}

Node* RBTree::find(int data) {
    Node* ptr = root;
    while (ptr != NULL) {
        if (ptr->data == data) return ptr;
        if (data < ptr->data)
            ptr = ptr->leftChild;
        else
            ptr = ptr->rightChild;
    }
    return ptr;
}

Node* RBTree::minNode() {
    if (root == NULL)
        return NULL;
    Node* linker = root;
    while (linker->leftChild != NULL)
        linker = linker->leftChild;
    return linker;
}

Node* RBTree::maxNode() {
    if (root == NULL)
        return NULL;
    Node* linker = root;
    while (linker->rightChild != NULL)
        linker = linker->rightChild;
    return linker;
}


Node* RBTree::upper_bound(int data) {
    // Node* linker = root;
    if (maxNode() == NULL || maxNode()->data <= data) 
        return NULL;
    Node* linker = root;
    while (1) {
        if (linker->leftChild != NULL) {
            int maxLeft = maximumLeft(linker)->data;
            if (maxLeft <= data)
                if (linker->data > data)
                    return linker;
                else 
                    linker = linker->rightChild;
            else
                linker = linker->leftChild;
        } else
            if (linker->data > data) 
                return linker;
            else
                linker = linker->rightChild;
    }
    //return NULL;
}



Node* RBTree::lower_bound(int data) {
    Node* linker = root;
    if (maxNode() == NULL || maxNode()->data < data) 
        return NULL;
    // Node* linker = root;
    while (1) {
        if (linker->leftChild != NULL) {
            int maxLeft = maximumLeft(linker)->data;
            if (maxLeft < data)
                if (linker->data >= data)
                    return linker;
                else 
                    linker = linker->rightChild;
            else
                linker = linker->leftChild;
        } else
            if (linker->data >= data) 
                return linker;
            else
                linker = linker->rightChild;
    }
}

Node* RBTree::minimumRight(Node *ptr) {
    if (ptr == NULL)
        return NULL;
    ptr = ptr->rightChild;
    while (ptr->leftChild != NULL)
        ptr = ptr -> leftChild;
    return ptr;
}

Node* RBTree::maximumLeft(Node *ptr) {
    if (ptr == NULL)
        return NULL;
    ptr = ptr->leftChild;
    while (ptr->rightChild != NULL)
        ptr = ptr -> rightChild;
    return ptr;
}


void RBTree::setParent(Node *&child, Node *&parent) {
    if (child == NULL) return;
    child->parent = parent;
}

Node* RBTree::otherChild(Node *parent, Node *child) {
    if (parent->leftChild == child)
        return parent->rightChild;
    else
        return parent->leftChild;
}
void RBTree::eraseFix(Node *&parent, Node *sibling) {
    if (parent == NULL) return;
    //cout << parent->data << " " << sibling->data << " " << "\n";
    //Node *sibling = (parent->leftChild == NULL) ? parent->rightChild : parent->leftChild;
    Node *leftChild = sibling->leftChild;
    Node *rightChild = sibling->rightChild;

    if (getColor(leftChild) == RED || getColor(rightChild) == RED) {
        if (parent -> leftChild == sibling) {
            if (getColor(leftChild) != RED) {
                setColor(sibling, RED);
                setColor(rightChild, BLACK);
                rotateLeft(sibling);
                sibling = sibling->parent;
                leftChild = sibling->leftChild;
            }
            int oldColor = getColor(parent);
            setColor(parent, BLACK);
            setColor(leftChild, BLACK);
            rotateRight(parent);
            setColor(sibling, oldColor);
        }
        else {
            //cout << "ok\n" ;
            if (getColor(rightChild) != RED) {
                setColor(sibling, RED);
                setColor(leftChild, BLACK);
                rotateRight(sibling);
                sibling = sibling->parent;
                rightChild = sibling->rightChild;
            }
            int oldColor = getColor(parent);
            setColor(parent, BLACK);
            setColor(rightChild, BLACK);
            rotateLeft(parent);
            setColor(sibling, oldColor);
        }
        return;
    }
    if (getColor(sibling) == BLACK) {
        setColor(sibling, RED);
        if (getColor(parent) == RED)     
            setColor(parent, BLACK);
        else
            eraseFix(parent->parent, getSibling(parent));
        return;
    }

    if (getColor(sibling) == RED) {
        Node* other = getSibling(sibling);
        setColor(sibling, BLACK);
        setColor(parent, RED);
        if (sibling == parent->rightChild)
            rotateLeft(parent);
        else
            rotateRight(parent);
        // cout << parent->color << " " << sibling->color << "\n\n";
        // (*this)._display_tree();
        eraseFix(parent, otherChild(parent, other));
        eraseFix(parent, sibling);
        return;
    }
}

Node* RBTree::getSibling(Node *ptr) {
    if (ptr == NULL || ptr->parent == NULL)
        return NULL;
    if (ptr->parent->leftChild == ptr)
        return ptr->parent->rightChild;
    else
        return ptr->parent->leftChild;
}

void RBTree::eraseNode(Node*& ptr) {
    Node* child = (ptr->leftChild == NULL) ? ptr->rightChild : ptr->leftChild;
    Node* parent = ptr->parent;
    // case one of ptr & child red

    if (ptr->color == RED || getColor(child) == RED) {
        //child->parent = parent;
        setParent(child, parent);
        // case ptr is root
        if (parent != NULL)
            if (parent->leftChild == ptr)
                parent->leftChild = child;
            else
                parent->rightChild = child;
        else
            root = child;
        setColor(child, BLACK); // child is red then set child as black
        delete ptr; // delete because we return right now
        return;
    }
    // luc nay ptr va child deu la mau den, nen se goi ham eraseFix
    Node* sibling = getSibling(ptr); // de tien hon cho ham eraseFix
    if (parent != NULL)
        if (parent->leftChild == ptr)
            parent->leftChild = NULL;
        else
            parent->rightChild = NULL;
    else
        root = child;
   
    delete ptr;
    eraseFix(parent, sibling);
}

void RBTree::erase(int data) {
    Node *ptr = find(data);   

    if (ptr->leftChild != NULL && ptr->rightChild != NULL) {
        Node *beErase = minimumRight(ptr);
        ptr->data = beErase->data;
        ptr = beErase;
    }
    //cout << ptr->data << "\n";
    eraseNode(ptr);
}


int RBTree::_get_height(Node *sr) {
	if (!sr)
        return -1;
	return 1 + max(_get_height(sr->leftChild), _get_height(sr->rightChild));
}


void _display_subtree(Node *q, vector<string> & output, int left, int top, int width)
{
	string str = to_string(q->data) + (q->color == RED ? "R":"B") + to_string(q->count);

	int left_begin_shift = 1 - (str.length()-1)/2;
	for (size_t i = 0; i < str.length() && left + width/2 + i < output[top].length(); i++)
		output[top][left + width/2 + left_begin_shift + i] = str[i];

	int branch_off_set = (width+3)/pow(2, 3);
	int mid = left + width/2;
	int left_mid = left + (width/2 - 1)/2;
	int right_mid = left + width/2 + 2 + (width/2 - 1)/2;

	if (q->leftChild)
	{
		int branch_position = mid - branch_off_set + 1;
		for (int pos = mid + left_begin_shift - 2; pos > branch_position; pos--)
			output[top][pos] = '_';
		output[top+1][branch_position] = '/';
		for (int pos = branch_position-1; pos > left_mid + 2; pos--)
			output[top+1][pos] = '_';
		_display_subtree(q->leftChild, output, left, top+2, width/2 - 1);
	}

	if (q->rightChild)
	{
		int branch_position = mid + branch_off_set + 1;
		for (int pos = mid + left_begin_shift + str.length() + 1; pos < branch_position; pos++)
			output[top][pos] = '_';
		output[top+1][branch_position] = '\\';
		for (int pos = branch_position+1; pos < right_mid; pos++)
			output[top+1][pos] = '_';
		_display_subtree(q->rightChild, output, left + width/2 + 2, top+2, width/2 - 1);
	}
}

void RBTree::_display_tree() {
    _display_tree(root);
}

void RBTree::_display_tree(Node *root) {
	if (root == NULL)
        return;

	int height = _get_height(root);
	int width_display = 4*pow(2, height) - 3;
	int height_display = 2 * height + 1;

	vector<string> output(height_display);
	for (size_t i = 0; i < output.size(); i++)
		output[i] = string(width_display + 4, ' ');

	_display_subtree(root, output, 0, 0, width_display);

	for (int row = 0; row < height_display; row++)
		cout << output[row] << endl;
}
