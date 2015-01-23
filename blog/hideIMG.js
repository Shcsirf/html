window.onload = function() {
	var images = document.getElementsByTagName("img");
	for(var i = 0; i < images.length; i++) {
		var image = images[i];
		if(image.addEventListener)
			image.addEventListener("click",hide,false);
		else
			image.attachEvent("onclick",hide);
	}
	function hide(event){
		var target = event.target ? event.target : event.srcElement;
		target.style.visibility = "hidden";
	}
};
