<?php

/**
 * @file
 * Token module integration.
 */

/**
 * Implements hook_tokens().
 */
function node_extra_tokens_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'node') {
    foreach ($tokens as $name => $original) {
      list($oname, $pad, $pad_length) = explode(':', $name);
      
      if ( $oname === 'nid' 
           && !empty($pad) && $pad === 'pad'  
           && !empty($pad_length) && is_numeric($pad_length) ) {        
        $replacements[$original] = str_pad($data['node']->nid, $pad_length, '0', STR_PAD_LEFT);
      }
    }
  }
  
  return $replacements;
}