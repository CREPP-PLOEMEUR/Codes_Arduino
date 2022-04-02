difference() {

union () {

cube([50,24,4],center=true);
    translate([0,0,7]) cube([30,10,10],center=true);
    translate([15,0,7]) rotate([0,90,0]) cylinder(r=3,h=6,center=true,$fn=80);

}
translate([0,10,0]) cube([18,5,8], center=true);

}