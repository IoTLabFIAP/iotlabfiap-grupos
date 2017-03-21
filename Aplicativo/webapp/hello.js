$(document).ready(function() {
    $.ajax({
        url: "sua-url-do-json"
    }).then(function(data) {
       $('.valor-1').append(data.id);
       $('.valor-2').append(data.content);
    });
});
