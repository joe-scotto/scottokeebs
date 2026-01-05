$fn = 80;

// Stabilizer cutout (Costar/Cherry style)
module stabilizer(width = 6, height = 14) {
    hull() {
        translate([-width/2,  height/2]) circle(r = 1.0);
        translate([ width/2,  height/2]) circle(r = 1.0);
        translate([-width/2, -height/2]) circle(r = 1.0);
        translate([ width/2, -height/2]) circle(r = 1.0);
    }
}

module key_cutout() {
    square(14.0, center = true);
}

module key_row(y_offset, x_positions) {
    for (x = x_positions)
        translate([x, y_offset]) key_cutout();
}

// Outer plate shape – your approach, now fixed and perfected
module plate() {
    difference() {
        hull() {
            translate([ 46,  37]) circle(r = 2);
            translate([-46,  37]) circle(r = 2);
            translate([ 65, -37]) circle(r = 2);
            translate([ 65,   0]) circle(r = 2);
            translate([-65, -37]) circle(r = 2);
            translate([-65,   0]) circle(r = 2);
        }

        // Left cut
        hull() {
            translate([-50, 4]) circle(r = 2);
            translate([-50, 37]) square(4, center = true);
            translate([-65, 4]) square(4, center = true);
        }
        // Right cut
        hull() {
            translate([50, 4]) circle(r = 2);
            translate([50, 37]) square(4, center = true);
            translate([65, 4]) square(4, center = true);
        }
        
    }
}

module vertical_scale() {
    line_thickness = 0.4;
    label_size = 5;
    label_x = -95;
    tick_start_x = -85;
    tick_length = 10;
    
    for (i = [-7:7]) {
        y = i * 20;
        translate([tick_start_x, y - line_thickness/2]) square([tick_length, line_thickness]);
        translate([label_x, y]) text(str(y), size = label_size, halign = "right", valign = "center");
    }
}

module horizontal_scale() {
    line_thickness = 0.4;
    label_size = 5;
    label_y = -95;
    tick_start_y = -85;
    tick_length = 10;
    
    for (i = [-7:7]) {
        x = i * 20;
        translate([x - line_thickness/2, tick_start_y]) square([line_thickness, tick_length]);
        translate([x, label_y]) text(str(x), size = label_size, halign = "center", valign = "top");
    }
}

module title_text() {
    translate([-140, 150]) text("/home/rholbert/repos/3d_hotswap_socket_pad/frog_plate.scad", size = 5, halign = "left");
}

module calibration_text() {
    translate([-140, -130]) 
        text("Scale is to calibrate actual printed dimension. Check both X and Y. Measure between tick 0 and last tick", 
             size = 5, halign = "left");
}

// Final technical drawing
union() {
    difference() {
        plate();
        
        // Central screw hole
        circle(r = 1.05);
        
        // Mounting holes
        translate([ 28.55,  19.1]) circle(r = 1.05);
        translate([ 45.35, -19.05]) circle(r = 1.05);
        translate([-28.55,  19.1]) circle(r = 1.05);
        translate([-45.35, -19.05]) circle(r = 1.05);
        
        // Switch cutouts
        key_row(28.575, [-38.1, -19.05, 0, 19.05, 38.1]);
        key_row(9.525,  [-38.1, -19.05, 0, 19.05, 38.1]);
        key_row(-9.525, [-38.1, -19.05, 0, 19.05, 38.1]);
        key_row(-28.575, [-33.3375, 0, 33.3375]);
        
        // Outer thumb keys
        translate([-57.15, -19.05]) key_cutout();
        translate([ 57.15, -19.05]) key_cutout();
        
        // Stabilizers
        translate([ 11.925, -27.075]) stabilizer();
        translate([-11.925, -27.075]) stabilizer();
        translate([-55.65,  -7.1]) rotate(90) stabilizer();
        translate([ 55.65,  -7.1]) rotate(90) stabilizer();
        translate([-55.65, -31.0]) rotate(90) stabilizer();
        translate([ 55.65, -31.0]) rotate(90) stabilizer();
    }
    
    vertical_scale();
    horizontal_scale();
    title_text();
    calibration_text();
}