<?php
/**
 * @file rus_livestream.defaults.inc
 * Set up initial livestream nodes per host on install.
 */

/**
 * Create host to stream maps.
 */
function rus_livestream_default_streams() {
  $streams = array(
    'visaa.tv' => array(
      '<iframe src="http://www.ustream.tv/embed/12394899" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275535" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275545" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275559" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275611" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
    ),
    'genevatv.org' => array(
      '<iframe src="http://www.ustream.tv/embed/11596426" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275815" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275821" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275829" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275835" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
    ),
    'flucotv.org' => array(
      '<iframe src="http://www.ustream.tv/embed/11679045" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275843" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275857" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275863" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275873" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
    ),
    'jeffersondistrictsportsnetwork.com' => array(
      '<iframe src="http://www.ustream.tv/embed/12100465" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275881" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275887" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275889" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
      '<iframe src="http://www.ustream.tv/embed/14275897" width="608" height="368" scrolling="no" frameborder="0" style="border: 0px none transparent;"></iframe><br />',
    ),
  );
  return $streams;
}

/**
 * Create the stream nodes based on the host we're installing on.
 */
function rus_livestream_default_stream_nodes($streams = array()){
  global $base_url;
  if (empty($base_url) || $base_url == 'http://default') {
    $base_url = 'http://jeffersondistrictsportsnetwork.com';
  }
  $domain = str_replace('http://', '', $base_url);
  if (empty($streams)) {
    $streams = rus_livestream_default_streams();
  }
  if (!empty($streams[$domain])) {
    $x = 0;
    foreach ($streams[$domain] as $embed_code) {
      $x++;
      $node = new stdClass();
      $node->type = 'livestream';
      $node->status = 1;
      $node->uid = 1;
      $node->language = LANGUAGE_NONE;
      $node->title = 'Channel ' . $x;
      $node->promote = 0;
      $node->body[LANGUAGE_NONE][0]['value'] = $embed_code;
      $node->body[LANGUAGE_NONE][0]['format'] = 'full_html';
      $node->comment = 0;
      node_submit($node);
      node_save($node);
    }
  }
}
