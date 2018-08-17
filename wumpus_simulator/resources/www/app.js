//---------------------GLOBAL_VARIABLES---------------------
var fieldSize = 0;
var traps = 0;
var wumpus = 0;


//---------------------ENTRY_POINT---------------------
$(document).ready(function() {

    //Activate materialize elements
    $('.dropdown-button').dropdown();
    $('.modal').modal();

    //Listen on click of the random button from the settings modal, to create some values
    $('#randomValuesBtn').click(function() {

        //Calculate the field size, number of traps and wumpus randomly
        fieldSize = Math.floor((Math.random() * 21) + 4); //Adjust the % value to the the upper bounce
        traps = Math.floor((Math.random() * (Math.pow(fieldSize, 2) / 4)) + 1);
        wumpus = Math.floor((Math.random() * fieldSize) + 1);

        //Set the random values
        $('#playgroundSize').val(fieldSize);
        $('#trapNumbers').val(traps);
        $('#wumpusNumbers').val(wumpus);
        $('#arrowAgent').prop('checked', (fieldSize % 2 === 0));

        //Update the text fields
        Materialize.updateTextFields();

    });

    //Listen on the close button from the settings modal
    $('#settingsCancel').click(function() {

        //Remove the last entry from the settings modal
        $('#playgroundSize').val('');
        $('#trapNumbers').val('');
        $('#wumpusNumbers').val('');
        $('#arrowAgent').prop('checked', false);
        Materialize.updateTextFields();

        //Just close the modal
        $('#newWorldModal').modal('close');

    });

    //Listen on the ok button from the settings modal
    $('#settingsOk').click(function() {

        //Check if there are all needed values
        if($('#playgroundSize').val() && $('#trapNumbers').val() && $('#wumpusNumbers').val()) {

            wumpus = $('#wumpusNumbers').val();
            traps = $('#trapNumbers').val();
            fieldSize = $('#playgroundSize').val();
            var hasArrow = $('#arrowAgent').prop('checked');

            if((+traps + +wumpus) > ((fieldSize*fieldSize) / 2)) {
                return;
            }

            setInitialValues(wumpus, traps, fieldSize, hasArrow);

            //Draw the playground
            drawPlayground();

            //This variable comes from qt, web interface. Creates the model
            wumpus_simulator.createWorld(hasArrow, wumpus, traps, fieldSize);

            //Remove the last entry from the settings modal
            $('#playgroundSize').val('');
            $('#trapNumbers').val('');
            $('#wumpusNumbers').val('');
            $('#arrowAgent').prop('checked', false);
            Materialize.updateTextFields();

            //Close the modal
            $('#newWorldModal').modal('close');

        }
    });

    //Listen on the save world button
    $('#save').click(function () {

        //Call save function from qt
        wumpus_simulator.saveWorld();

    });

    //Listen on the load world button
    $('#load').click(function() {

        //call load function from qt
        wumpus_simulator.loadWorld();

    });
});


//---------------------METHODS---------------------
//Set the variables from the info bar
function setInitialValues(w, t, f, a) {

    //Set the labels from the info bar
    $('#arrow').text('Arrow: ' + Boolean(a));
    $('#wumpus').text('Wumpus: ' + w);
    $('#traps').text('Traps: ' + t);
    $('#size').text('Size: ' + f);

    fieldSize = f;
    traps = t;
    wumpus = w;

}

//Draws the playground, just a grid depending on the field size
function drawPlayground() {

    //Get the table as root
    var root = $('#board');

    //Clear the board
    root.empty();

    //Create html grid content
    var grid = '';

    for(var i = 0; i < fieldSize; i++) {

        //Append a row
        grid += '<div style="line-height: 1px;">';

        for(var j = 0; j < fieldSize; j++) {

            //Append a new cell to the last row, the size of a single cell is set in the ground css class in the style.css
            grid += '<div class="ground"></div>';

        }

        //Close the row div
        grid += '</div>'

    }

    //Add the grid to the board
    root.html(grid);


}

function clearTiles() {
    $('.ground').empty();
}

function addWumpusImage(i, j) {
      $($('.ground')[i*fieldSize+j]).prepend('<img class="secondImage" src="img/wumpus.png" > </img>');
}

function addTrapImage(i, j) {
      $($('.ground')[i*fieldSize+j]).prepend('<img class="secondImage" src="img/trap.png" > </img>');
}

function addStenchImage(i, j) {
      $($('.ground')[i*fieldSize+j]).prepend('<img class="thirdImage" src="img/stench.png" > </img>');
}

function addBreezeImage(i, j) {
      $($('.ground')[i*fieldSize+j]).prepend('<img class="fourthImage" src="img/breeze.png" > </img>');
}

function addGoldImage(i, j) {
    $($('.ground')[i*fieldSize+j]).prepend('<img class="secondImage" src="img/gold.png" > </img>');
}

function addDirtImage(i, j) {
    $($('.ground')[i*fieldSize+j]).prepend('<img class="firstImage" src="img/ground.png" > </img>');
}

function addAgent(i, j, agentID, gender, heading) {

    var html = '<img id="' + agentID + '" class="fifthImage" src="img/' + gender + 'Agent';

    switch (heading) {

        case 0:
            html += 'Up';
            break;

        case 1:
            html += 'Left';
            break;

        case 2:
            html += 'Down';
            break;

        case 3:
            html += 'Right';
            break;

        default:
            break;
    }

    html += '.png" > </img>';

    $($('.ground')[i*fieldSize+j]).prepend(html);

}

function addEntryPoint(i, j) {
    $($('.ground')[i*fieldSize+j]).prepend('<img class="fourthImage" src="img/start.png" > </img>');
}

