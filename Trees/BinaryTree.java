import java.io.*;
import java.util.*;
class node
{
    int data;
    node left;
    node right;
}
class btree
{
    public static node returnode(int k)
    {
        node new_node = new node();
        new_node.data=k;
        new_node.left=null;
        new_node.right=null;
        return new_node;
    }
    public static node insert(node root,int k)
    {
        if(root==null){
            return returnode(k);
        }
        else{
            if(k<root.data)
            {
                root.left=insert(root.left,k);
            }
            else{
                root.right=insert(root.right,k);
            }
            return root;
        }
    }
}
class Ideone
{
    public static void inorder(node root)
    {
        if(root!=null)
        {
            inorder(root.left);
            System.out.println(root.data);
            inorder(root.right);
        }
    }
    public static int computeheight(node root)
    {
        if(root==null)
        {
            return 0;
        }
        int lsubtree=computeheight(root.left);
        int rsubtree=computeheight(root.right);
        
        return Math.max(lsubtree,rsubtree)+1;
        
    }
    public static int diameter(node root)
    {
    	int ans=-99999;
        if(root==null)
        {
            return 0;
        }
        int lsubtree=computeheight(root.left);
        int rsubtree=computeheight(root.right);
        ans=Math.max(ans,lsubtree+rsubtree+1);
        return ans;
    }
    public static boolean checkbalanced(node root)
    {
        if(root==null){
            return true;
        }
        int lsubtree=lheight(root.left);
        int rsubtree=rheight(root.right);
        
        if((Math.abs(lsubtree-rsubtree))>1 && checkbalanced(root.left) && checkbalanced(root.right))
        {
            return true;
        }
        return false;
    }
    public static int lheight(node root){
        if(root==null){
            return 0;
        }
        return 1+lheight(root.left);
    }
    public static int rheight(node root){
        if(root==null){
            return 0;
        }
        return 1+rheight(root.right);
    }
    public static boolean checkbst(node root)
	{
		if(root==null){
			return true;
		}
		if(root.left==null || root.right==null){
			return true;
		}
		if(root.data > (root.left.data) && root.data<(root.right.data) && checkbst(root.left)==true && checkbst(root.right)==true)
		{
			return true;
		}
		return false;
	}
	public static node lca(node root,int node1,int node2)
	{
		if(root==null){
			return null;
		}
		if(root.data==node1 || root.data==node2)
		{
			return root;
		}
		node left=lca(root.left,node1,node2);
		node right=lca(root.right,node1,node2);
		if(left!=null && right!=null)
		{
			return root;
		}
		if(left==null && right==null){
			return null;
		}
		if(left!=null){
			return left;
		}
		return right;
	}
	public static void main (String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		btree tree= new btree();
		node root=null;
		for(int i = 0 ; i < n ; i ++ )
		{
		    int x=sc.nextInt();
		    root=tree.insert(root,x);
		}
		System.out.println(computeheight(root));
	    inorder(root);
	    System.out.println(checkbalanced(root));
	    System.out.println(checkbst(root));
	    System.out.println(diameter(root));
	}
}
