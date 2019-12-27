<h1>Binary Search Tree</h1>
<div><h3>Definition: </h4> A binary tree in which given any node x, all elements in the subtree rooted at x<sub>left-child</sub> &le; x and all elements in the subtree rooted at x<sub>right-child</sub>  &ge; x. In practice, if an element is equal to x, it gets pushed to one of the subtrees in a deterministic way.</div>
<div><h3>Operations and Running-time:</h3>
	<div><h4>In-order tree traversal: </h4>
	Prints out the elements in a sorted order. Runs in Linear time.</div>
	<div><h4>Querying for a node: </h4>
	if key<sub>query</sub> &le; key<sub>root</sub>, then check key<sub>left-child-root</sub> else key<sub>right-child-root</sub>. The algorithm traverses the height of the tree hence runs in O(<i>h</i>) where <i>h</i> is the height of the tree.</div>
	<div><h4>Minimum and Maximum node: </h4> From root, follow the left child pointers till a leaf node is reached. This finds minimum-node. Similary,
	following the right child pointers till a leaf node is reached will find the maximum node. Both procedures run in O(<i>h</i>) where <i>h</i> is the height of the tree.</div>
	<div>
		<h4>Successor for a node <i>x</i>: </h4>
		<u>Case :Right child of <i>x</i> present</u>: 
		x<sub>successor</sub> = Tree-Minimum (subtree rooted at x<sub>right-child</sub>)<br/>
		<u>Case :Right child of <i>x</i> missing</u>:
		x<sub>successor</sub> = Closest Ancestor of <i>x</i> whose left-subtree contains <i>x</i>
	</div>
	<div>
		<h4>Predecessor for a node <i>x</i>: </h4>
		<u>Case :Left child of <i>x</i> present</u>: 
		x<sub>predecessor</sub> = Tree-Maximum (subtree rooted at x<sub>left-child</sub>)<br/>
		<u>Case :Left child of <i>x</i> missing</u>:
		x<sub>predecessor</sub> = Closest Ancestor of <i>x</i> whose right-subtree contains <i>x</i>
	</div>
</div>