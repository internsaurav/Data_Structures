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
	<p>Both successor and predecessor run in O(<i>h</i>) time</p>
	</div>
	<div>
		<h4>Delete a node <i>x</i>: </h4>
		<div>
			<u>Case : <i>x</i> has no children</u>:
			Set <i>Parent</i><sub>x</sub>'s (if present) pointer to <i>x</i> = NULL<br/>
			<u>Case : <i>x</i> has one child <i>x</i><sub>Child</sub></u>:
			Set <i>Parent</i><sub>x</sub>'s (if present) pointer to <i>x</i> = <i>x</i><sub>Child</sub><br/>
			If <i>Parent</i><sub>x</sub> is null, this means <i>x</i> is the Root of the tree. In this case
			<i>x</i><sub>Child</sub> becomes the new root of the tree. Nothing else changes.<br/>
			<u>Case : <i>x</i> has both children</u>:
			<ol>
				<li><i>x</i><sub>successor</sub> becomes the new root of the subtree rooted at <i>x</i>.</li>
				<li>Set <i>Parent</i><sub>x</sub>'s (if present) pointer to <i>x</i> = <i>x</i><sub>successor</sub>, otherwise
					<i>x</i><sub>successor</sub> becomes the tree root.</li>
			</ol>
			<p> For 2) above, plucking out the successor from its existing position is a little tricky.
				If <i>x</i><sub>successor</sub> happens to be the right-child of <i>x</i>, we just raise <i>x</i><sub>successor</sub> to the position of <i>x</i>.<br/>
				If <i>x</i><sub>successor</sub> is not the right-child of <i>x</i>, we need to note that <i>x</i><sub>successor</sub> must be the left-child of its parent (Parent<sub><i>x</i><sub>successor</sub></sub>). It might point to a subtree as its right-child. <br/>
				<b><u>Procedure: </u></b>
				<ol>
					<li>Set the left-child pointer of Parent<sub><i>x</i><sub>successor</sub></sub> = <i>x</i><sub>successor<sub>right-child</sub></sub>.</li>
					<li>Set Parent pointer of <i>x</i><sub>successor<sub>right-child</sub></sub> = Parent<sub><i>x</i><sub>successor</sub></sub></li>
					<li>Set left-child pointer of <i>x</i><sub>successor</sub> = left-child pointer of <i>x</i>.</li>
					<li>Set right-child pointer of <i>x</i><sub>successor</sub> = right-child pointer of <i>x</i>.</li>
				</ol>
			</p>
		</div>
	</div>

</div>