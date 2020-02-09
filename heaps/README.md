<h1>Binary Heaps</h1>
<div>
	<span><h4>Definition: </h4>
		It is a <ul>
	 	<li>Tree</li>
	 	<li>Binary Tree</li>
	 	<li>Complete Binary Tree (All levels filled except last level. Last level has to be filed from left to right)</li>
	 </ul>
	Since this is a complete binary tree, the elements can be stored in an array in a contiguous manner. For any node <i>x</i> present at index <i>i</i>,
	<ul>
		<li><i>x</i><sub>left-child</sub> will be found at index <i>2*i</i>, if present.</li>
		<li><i>x</i><sub>right-child</sub> will be found at index <i>2*i+1</i>, if present.</li>
		</ul>	
	</span>
	<span>
		<figure>
			<img src="assets/binary_max_heap.JPG" width="50%" align="middle">
			<figcaption>Example of a binary heap (This is a Max-heap)</figcaption>
		</figure>
		<figure>
			<img src="assets/array_rep.JPG" width="50%"  align="middle">
			<figcaption>Array representation of the same</figcaption>
		</figure>
	</span>
</div>
<div><h4> Max and Min-heaps: </h4>
	Max-heap is a heap where the child subtrees of a node cannot have an element greater than the node itself. Min-heap is the opposite.
	Max-heap is used for heap-sort algorithm. Min-heap is used for implementing <b>Priority-Queues</b>.
</div>

<div>
	<h4>Questions:</h4>
	<p>
		<question><b>What are the minimum and maximum number of elements in a heap pf height <i>h</i>?</b></question>
		<answer>Atleast <i>h-1</i> levels are completely filled.Hence, minimum would be 2<sup>0</sup>+2<sup>1</sup>+....+2<sup>h-1</sup>+1. Maximum would be 2<sup>0</sup>+2<sup>1</sup>+....+2<sup>h</sup>.</answer>
	</p>
	<p>
		<question><b>Where in a max-heap might the smallest elements reside, assuming that all elements are distinct?</b></question>
		<answer>If all elements are distinct, each level of nodes is greater than its lower level. Hence the minimum element must reside somewhere among the leaf-nodes.</answer>
	</p>
	<p>
		<question><b>Is a sorted array a min-heap?</b></question>
		<answer>yes!</answer>
	</p>

</div>

<!-- <div><h3>Operations and Running-time:</h3>
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
 -->
</div>