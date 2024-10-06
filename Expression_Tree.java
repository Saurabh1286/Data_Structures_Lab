import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Stack {
    Node[] stk;
    int top;

    Stack () {
        this.stk = new Node[100];
        this.top = -1;
    }

    void push (Node pushNode) {
        if (top == 99) {
            return;
        }
        stk[++top] = pushNode;
    }

    Node pop () {
        if (top == -1) {
            return null;
        }
        return stk[top--];
    }

    Node peek () {
        if (top == -1) {
            return null;
        }
        return stk[top];
    }
}

class Node {
    String data;
    Node left, right;

    Node (String data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class Binary_Search_Tree {
    Node root;

    Binary_Search_Tree () {
        this.root = null;
    }

    void inorder () {
        inorder_priv (this.root);
    }

    private void inorder_priv (Node root) {
        if (root == null) {
            return ;
        }
        inorder_priv(root.left);
        System.out.print(root.data);
        inorder_priv(root.right);
    }
}

public class Expression_Tree {

    static Binary_Search_Tree expression_tree (String[] expressionArray) {
        String operators = "+-*/^";

        Binary_Search_Tree bst = new Binary_Search_Tree();

        Stack exp_stack = new Stack();

        for (String i : expressionArray) {
            Node temp = new Node(i);

            if (!operators.contains(temp.data)) {
                exp_stack.push(temp);
            }
            else {
                temp.right = exp_stack.pop();
                temp.left = exp_stack.pop();
                exp_stack.push(temp);
            }
        }

        bst.root = exp_stack.peek();

        return bst;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter a expression : ");
        String[] expressionArray = in.readLine().replaceAll("\\s+$", "").split("");
        Binary_Search_Tree bst = Expression_Tree.expression_tree(expressionArray);
        System.out.print("Infix Expression : ");
        bst.inorder();
    }
}