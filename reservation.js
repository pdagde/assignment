
function hotelReservation(str){
	var finalHotel = '';
	var finalRating = 0;
	var hotelmenu = [{"name":"Lakewood", rating:3, "weekday_reg" : 110, "weekday_rew":80,"weekend_reg":90,"weekend_rew":80},
	                 {"name":"Bridgewood", rating:4, "weekday_reg" : 160, "weekday_rew":100,"weekend_reg":60,"weekend_rew":50},
	                 {"name":"Ridgewood", rating:5, "weekday_reg" : 220, "weekday_rew":100,"weekend_reg":150,"weekend_rew":40}

	                 ]
	
temp = str.split(":");

  var alldates = temp[1].split(",");
	  var totalAmount = 0;
	  for(var j in hotelmenu){
	  	var amount = 0;
	  	  for(var i in alldates){
	  	  	 var day = alldates[i].match(/\(([^)]+)\)/)[1];
	  	  	  if(day=='sat' || day=='sun'){
	  	  	  	  if(temp[0]=="Regular"){
	  	  	  	  	amount=amount+hotelmenu[j].weekend_reg;
	  	  	  	  }
	  	  	  	  	else{
	  	  	  	         amount=amount+hotelmenu[j].weekend_rew;		
	  	  	  	  	}
	  	  	  }else{
			  	  	  	  if(temp[0]=="Regular"){
			  	  	  	  	amount=amount+hotelmenu[j].weekday_reg;
			  	  	  	  }
			  	  	  	  	else{
			  	  	  	         amount=amount+hotelmenu[j].weekday_rew;		
			  	  	  	  	}
	  	  	  }


              
	  	  }  

               if(totalAmount == 0){
               	  totalAmount = amount;
               	  finalHotel = hotelmenu[j].name;
               	  finalRating = hotelmenu[j].rating;
               }else if(totalAmount == amount){
                     if(finalRating < hotelmenu[j].rating){
                         totalAmount = amount;
                   finalHotel = hotelmenu[j].name;
                   finalRating = hotelmenu[j].rating;
                     }
               }
               else if(totalAmount > amount){
                   totalAmount = amount;
                   finalHotel = hotelmenu[j].name;
                   finalRating = hotelmenu[j].rating;
               }

	  	 }
        return finalHotel;

	  }
	









function hotelReservationMain(){
    
var input = ["Regular: 16Mar2009(mon), 17Mar2009(tues), 18Mar2009(wed)",
             "Regular: 20Mar2009(fri), 21Mar2009(sat), 22Mar2009(sun)",
             "Rewards: 26Mar2009(thur), 27Mar2009(fri), 28Mar2009(sat)"];


             for(var i in input){
                   console.log("selected Hotel",hotelReservation(input[i]));
             }
}


hotelReservationMain();



