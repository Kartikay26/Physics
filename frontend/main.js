var s = io("http://localhost:5000");
// use like: resp = await s.get("ping", "data")
s.get = function (event, ...payload) {
    return new Promise(function (resolve, reject) {
        return s.emit(event, ...payload, function (...args) {
            return resolve(...args);
        })
    })
}
// ============================================================================

var frames = 0;
var data = {};
var w = window.innerWidth;
var h = window.innerHeight;
var running = true;
var zoom = 0.5;
var time = 0;
var timestep = 0.00025;

var xScale = d3.scaleLinear()
    .domain([-15 / zoom, 15 / zoom])
    .range([0, w]);
var yScale = d3.scaleLinear()
    .domain([-15 * (h / w) / zoom, 15 * (h / w) / zoom])
    .range([h, 0]);
var massScale = d3.scaleLinear()
    .domain([0, 10 / zoom])
    .range([0, 50]);

// ---------------------------------------------------------------------------

function drawdata(data, t) {
    var xScale = d3.scaleLinear()
        .domain([-15 / zoom, 15 / zoom])
        .range([0, w]);
    var yScale = d3.scaleLinear()
        .domain([-15 * (h / w) / zoom, 15 * (h / w) / zoom])
        .range([h, 0]);
    var massScale = d3.scaleLinear()
        .domain([0, 10 / zoom])
        .range([0, 50]);
    var circles = d3.select("#draw")
        .selectAll("circle")
        .data(data.particles);
    var springs = d3.select("#draw")
        .selectAll("line.spring")
        .data(data.springs);
    circles
        .enter()
        .append("circle")
        .transition()
        .attr("r", (d) => massScale(d.mass))
        .attr("class", (d) => d.type == "fixed" ? "particle fixed" : "particle")
    circles
        .attr("cx", (d) => xScale(d.pos[0] - 0.5 * d.pos[1]))
        .attr("cy", (d) => yScale(d.pos[2] - 0.5 * d.pos[1]))
        .attr("r", (d) => massScale(d.mass));
    springs
        .enter()
        .append("line")
        .style("opacity", "0.0")
        .transition()
        .style("opacity", "1.0")
        .attr("class", "spring");
    springs
        .attr("x1", (d) => xScale(d.p1[0] - 0.5 * d.p1[1]))
        .attr("y1", (d) => yScale(d.p1[2] - 0.5 * d.p1[1]))
        .attr("x2", (d) => xScale(d.p2[0] - 0.5 * d.p2[1]))
        .attr("y2", (d) => yScale(d.p2[2] - 0.5 * d.p2[1]))
        .attr("stroke", "#fff");
    circles
        .exit()
        .transition()
        .attr("r", 0.0)
        .remove();
    springs
        .exit()
        .transition()
        .style("stroke-opacity", "0")
        .remove();
    // TODO later on add code to show results in 3D
}

// ---------------------------------------------------------------------------

var saved_data;

var ix = 0;

async function replay_loop() {
    data_ = await s.get("saved_data", ix);
    if (data_ == "restart") {
        drawdata({ 't': 0, "particles": [], "springs": [] });
        ix = 0;
        setTimeout(() => {
            requestAnimationFrame(replay_loop);
        }, 2000);
        return;
    } else {
        data = data_;
    }
    ix += 1;
    drawdata(data);
    requestAnimationFrame(replay_loop);
}

async function setup() {
    s.get("reload_file")
    replay_loop()
}

$(setup);