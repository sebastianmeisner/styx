<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="virtex6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="in_tc" />
        <signal name="clk" />
        <signal name="stop" />
        <signal name="XLXN_6" />
        <port polarity="Input" name="in_tc" />
        <port polarity="Input" name="clk" />
        <port polarity="Output" name="stop" />
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="fd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
        </blockdef>
        <block symbolname="or2" name="XLXI_1">
            <blockpin signalname="stop" name="I0" />
            <blockpin signalname="in_tc" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="fd" name="XLXI_2">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_6" name="D" />
            <blockpin signalname="stop" name="Q" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1008" y="816" name="XLXI_1" orien="R0" />
        <instance x="1424" y="976" name="XLXI_2" orien="R0" />
        <branch name="in_tc">
            <wire x2="1008" y1="688" y2="688" x1="976" />
        </branch>
        <iomarker fontsize="28" x="976" y="688" name="in_tc" orien="R180" />
        <branch name="clk">
            <wire x2="1424" y1="848" y2="848" x1="1392" />
        </branch>
        <iomarker fontsize="28" x="1392" y="848" name="clk" orien="R180" />
        <branch name="stop">
            <wire x2="1008" y1="752" y2="752" x1="928" />
            <wire x2="928" y1="752" y2="976" x1="928" />
            <wire x2="1888" y1="976" y2="976" x1="928" />
            <wire x2="1888" y1="720" y2="720" x1="1808" />
            <wire x2="1888" y1="720" y2="976" x1="1888" />
            <wire x2="1984" y1="720" y2="720" x1="1888" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="1424" y1="720" y2="720" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1984" y="720" name="stop" orien="R0" />
    </sheet>
</drawing>