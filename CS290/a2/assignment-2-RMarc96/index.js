
///////////////////////////////////////////////////////////
// ASSIGNMENT 2: JAVASCRIPT
// BY RONALD SALINAS
// DESCRIPTION: ADDS FUNCTIONALITY TO THE TODO LIST SITE
/////////////////////////////////////////////////////////// 
 
//THIS IS USED TO MAKE MY LIFE EASIER
var main = document.getElementsByTagName('main')[0];
var backdrop = document.getElementById('modal-backdrop');
var modal = document.getElementById('add-note-modal');
var addNoteButton = document.getElementById('add-note-button');
var modalCancel = document.getElementsByClassName('modal-cancel-button')[0];
var modalCloseButton = document.getElementsByClassName('modal-close-button')[0];
var noteRemoveButtonArray = document.getElementsByClassName('dismiss-button');
var todoNoteBodyArray = document.getElementsByClassName('todo');
var modalAcceptButton = document.getElementsByClassName('modal-accept-button')[0];
 
 //THIS REVEALS THE MODAL AND MODAL BACKDROP
 function showModal() {
	//console.log("== Showing!");
	backdrop.style.display = 'block';
	modal.style.display = 'block';
};


//THIS HIDES THE MODAL AND MODAL BACKDROP 
 function hideModal() {
	//console.log("== Hiding!");
	backdrop.style.display = 'none';
	modal.style.display = 'none';
 };
 
 //THIS CLEARS THE PREVIOUS CONTENTS OF THE MODAL
 function modalClear() {
	document.getElementById('todo-input-what').value = "";
	document.getElementById('todo-input-where').value = "";
	document.getElementById('todo-input-when').value = "";
	document.getElementById('todo-input-who').value = "";
	document.getElementById('todo-input-details').value = "";
 };
 
 
 //THIS ADDS A NEW NOTE SECTION TO MAIN
 function addNewNote(event) {

	var newNote = document.createElement('section');
	newNote.className = 'todo';
	var noteBody = document.createElement('div');
	noteBody.className = 'todo-body';
	
	
	if(document.getElementById('todo-input-what').value.length != 0) {
		
		var whatField = document.createElement('h2');
		var enterWhat = document.createTextNode(document.getElementById('todo-input-what').value);
		whatField.appendChild(enterWhat);
	
		if(document.getElementById('todo-input-where').value.length != 0) {
			var whereField = document.createElement('p')
			whereField.className = 'indent-wrapped';
		
			var whereSpan = document.createElement('span');
			whereSpan.className = 'where';
			whereSpan.appendChild(document.createTextNode('where: '));
	
			var enterWhere = document.createTextNode(document.getElementById('todo-input-where').value);
	
			whereField.appendChild(whereSpan);
			whereField.appendChild(enterWhere);
			noteBody.appendChild(whereField);
	
		}
	
		if(document.getElementById('todo-input-when').value.length != 0) {
			var whenField = document.createElement('p')
			whenField.className = 'indent-wrapped';
	
			var whenSpan = document.createElement('span');
			whenSpan.className = 'when';
			whenSpan.appendChild(document.createTextNode('when: '));
	
			var enterWhen = document.createTextNode(document.getElementById('todo-input-when').value);
	
			whenField.appendChild(whenSpan);
			whenField.appendChild(enterWhen);
			noteBody.appendChild(whenField);
	
		}
	
		if(document.getElementById('todo-input-who').value.length != 0) {
			var whoField = document.createElement('p')
			whoField.className = 'indent-wrapped';
	
			var whoSpan = document.createElement('span');
			whoSpan.className = 'who';
			whoSpan.appendChild(document.createTextNode('who: '));
	
			var enterWho = document.createTextNode(document.getElementById('todo-input-who').value);
	
			whoField.appendChild(whoSpan);
			whoField.appendChild(enterWho);
			noteBody.appendChild(whoField);
	
		}
	
		if(document.getElementById('todo-input-details').value != 0) {
			var detailsField = document.createElement('p');
			detailsField.appendChild(document.createTextNode(document.getElementById('todo-input-details').value));
		
			noteBody.appendChild(detailsField);
		}
	
		var dismiss = document.createElement('div');
		dismiss.className = 'dismiss-button';
		dismiss.appendChild(document.createTextNode('×'));
		dismiss.addEventListener('click', removeNote);

	
		newNote.appendChild(whatField);
		newNote.appendChild(noteBody);
		newNote.appendChild(dismiss);
		main.appendChild(newNote);
	
	}
	
	modalClear();
	hideModal();
	
 };
 
 //THIS DELETES A TODO SECTION OF MAIN
 function removeNote(event) {

	//console.log("== Removing!" + event.target);
	var clickedNote = event.target;
	 
	clickedNote.parentNode.parentNode.removeChild(clickedNote.parentNode)
	
 };

 
//THESE ADD CLICK EVENTS TO WHEREVER THERE SHOULD BE CLICK EVENTS
addNoteButton.addEventListener('click', showModal);
modalAcceptButton.addEventListener('click', addNewNote);
modalCancel.addEventListener('click', hideModal);
modalCloseButton.addEventListener('click', hideModal);

for(var i = 0; i < document.getElementsByClassName('todo').length; i++) {
	noteRemoveButtonArray[i].addEventListener('click', removeNote)
};


